#include "framework.h"
#include "CPlayerHead.h"
#include "CAnimation.h"
#include "CAnimator.h"
#include "CRhythemManager.h"
#include "CMissedText.h"


void CPlayerHead::CreateMissedText()
{

	CMissedText* pMissedText = new CMissedText;
	pMissedText->SetPos(fPoint(WINSIZEX / 2 - 20.f, WINSIZEY - 60.f));
	pMissedText->SetDir(fVec2(0, -1));
	pMissedText->SetName(L"Missed_Text");

	CreateObj(pMissedText, GROUP_GAMEOBJ::MISSED_TEXT);

}

CPlayerHead::CPlayerHead()
{
	m_bAcctive = false;
	m_bStateRight = true;

	CD2DImage* m_pImgHead = CResourceManager::getInst()->LoadD2DImage(L"PlayerHeadImg", L"texture\\Character\\player1_heads.png");
	SetName(L"Player_Head");
	SetScale(fPoint(48.f, 48.f));


	CreateAnimator();
	GetAnimator()->CreateAnimation(L"RightHeadNone", m_pImgHead, fPoint(0.f, 0.f), fPoint(48.f, 48.f), fPoint(48.0f, 0.f), 0.08f, 4, false);
	GetAnimator()->CreateAnimation(L"RightHeadMove", m_pImgHead, fPoint(0.f, 0.f), fPoint(48.f, 48.f), fPoint(48.0f, 0.f), 0.08f, 4, false);
	GetAnimator()->CreateAnimation(L"LeftHeadNone", m_pImgHead, fPoint(0.f, 0.f), fPoint(48.f, 48.f), fPoint(48.0f, 0.f), 0.08f, 4, true);
	GetAnimator()->CreateAnimation(L"LeftHeadMove", m_pImgHead, fPoint(0.f, 0.f), fPoint(48.f, 48.f), fPoint(48.0f, 0.f), 0.08f, 4, true);


	CAnimation* pAni;
	pAni = GetAnimator()->FindAnimation(L"RightHeadMove");	// �Ӹ��� ���������� ������ �� ������ ����
	pAni->GetFrame(1).fptOffset = fPoint(0.f, -15.f);
	pAni->GetFrame(2).fptOffset = fPoint(0.f, -5.f);

	pAni = GetAnimator()->FindAnimation(L"LeftHeadMove");	// �Ӹ��� �������� ������ �� ������ ����
	pAni->GetFrame(1).fptOffset = fPoint(0.f, -15.f);
	pAni->GetFrame(2).fptOffset = fPoint(0.f, -5.f);

	GetAnimator()->Play(L"RightHeadNone");
}

CPlayerHead::~CPlayerHead()
{
}

CPlayerHead* CPlayerHead::Clone()
{
	return new CPlayerHead(*this);
}

void CPlayerHead::render()
{
	component_render();
}

void CPlayerHead::update()
{
	update_Move();
	update_Ani();

	if (nullptr != GetAnimator())
		GetAnimator()->update();

	if (CRhythemManager::getInst()->OneBit()) // 1���ڸ��� �ൿ ���� False�� �ʱ�ȭ
	{
		m_bAcctive = false;
	}
}

void CPlayerHead::update_Move()
{
	if (KeyDown(VK_UP))
	{
		if (CRhythemManager::getInst()->Success())			// Ÿ�̹� �°� ������ ��
		{
			if (false == m_bAcctive)
			{
				m_bAcctive = true;
				m_bSuccessed = StateMoveHead::UP;
			}
		}
		else												// Ÿ�̹� Ʋ���� ������ ��
		{
			if (false == m_bAcctive)
			{
				CreateMissedText();
				m_bAcctive = true;
			}
		}
	}
	else if (KeyDown(VK_DOWN))
	{
		if (CRhythemManager::getInst()->Success())			// Ÿ�̹� �°� ������ ��
		{
			if (false == m_bAcctive)
			{
				m_bAcctive = true;
				m_bSuccessed = StateMoveHead::DOWN;
			}
		}
		else												// Ÿ�̹� Ʋ���� ������ ��
		{
			if (false == m_bAcctive)
			{
				CreateMissedText();
				m_bAcctive = true;
			}
		}
	}
	else if (KeyDown(VK_LEFT))
	{
		if (CRhythemManager::getInst()->Success())			// Ÿ�̹� �°� ������ ��
		{
			if (false == m_bAcctive)
			{
				m_bAcctive = true;
				m_bSuccessed = StateMoveHead::LEFT;
				m_bStateRight = false;
			}
		}
		else												// Ÿ�̹� Ʋ���� ������ ��
		{
			if (false == m_bAcctive)
			{
				CreateMissedText();
				m_bAcctive = true;
			}
		}
	}
	else if (KeyDown(VK_RIGHT))
	{
		if (CRhythemManager::getInst()->Success())			// Ÿ�̹� �°� ������ ��
		{
			if (false == m_bAcctive)
			{
				m_bAcctive = true;
				m_bSuccessed = StateMoveHead::RIGHT;
				m_bStateRight = true;
			}
		}
		else												// Ÿ�̹� Ʋ���� ������ ��
		{
			if (false == m_bAcctive)
			{
				CreateMissedText();
				m_bAcctive = true;
			}
		}
	}
}

void CPlayerHead::update_Ani()
{
	fPoint pos = GetPos();
		
	if (m_bSuccessed == StateMoveHead::UP)						// �� ����Ű ������ ���
	{
		if (m_bStateRight)										// ���� �ٶ󺸰� �ִ� ���� Ȯ��
			GetAnimator()->Play(L"RightHeadMove");				// ������ �Ӹ� �̵� ���
		else
			GetAnimator()->Play(L"LeftHeadMove");				// ����   �Ӹ� �̵� ���

		// TODO : �� �ȼ� �Ÿ� Ȯ�� �� �ش� �Ÿ���ŭ �����̰� ���� �߰�
		pos.y -= 150.f * fDT;									// ���� �̵�

		m_fMovingTerm += fDT;									// �����̴� �� ���ϱ� ���� �ð� ����
		if (m_fMovingTerm > 0.32)								// 0.48��(�ִϸ����� �ð�) �ʰ� �� ���
		{
			m_bSuccessed = StateMoveHead::NONE;					// ���� NONE���� �ٲ�
			m_fMovingTerm = 0;									// �ð� 0�ʷ� �ʱ�ȭ

			if (m_bStateRight)									// ���� �ٶ󺸰� �ִ� ���� Ȯ��
				GetAnimator()->Play(L"RightHeadNone");			// ������ �Ӹ� ��� ���
			else
				GetAnimator()->Play(L"LeftHeadNone");			// ����   �Ӹ� ��� ���
		}
	}
	else if (m_bSuccessed == StateMoveHead::DOWN)				// �Ʒ� ����Ű ������ ���
	{
		if (m_bStateRight)									
			GetAnimator()->Play(L"RightHeadMove");			
		else
			GetAnimator()->Play(L"LeftHeadMove");			

		// TODO : �� �ȼ� �Ÿ� Ȯ�� �� �ش� �Ÿ���ŭ �����̰� ���� �߰�
		pos.y += 150.f * fDT;									// �Ʒ��� �̵�

		m_fMovingTerm += fDT;							
		if (m_fMovingTerm > 0.32)
		{
			m_bSuccessed = StateMoveHead::NONE;			
			m_fMovingTerm = 0;							

			if (m_bStateRight)							
				GetAnimator()->Play(L"RightHeadNone");	
			else
				GetAnimator()->Play(L"LeftHeadNone");	
		}
	}
	else if (m_bSuccessed == StateMoveHead::LEFT)				// ���� ����Ű ������ ���
	{
		GetAnimator()->Play(L"LeftHeadMove");				

		// TODO : �� �ȼ� �Ÿ� Ȯ�� �� �ش� �Ÿ���ŭ �����̰� ���� �߰�
		pos.x -= 150.f * fDT;									// �������� �̵�

		m_fMovingTerm += fDT;
		if (m_fMovingTerm > 0.32)
		{
			m_bSuccessed = StateMoveHead::NONE;
			m_fMovingTerm = 0;
			GetAnimator()->Play(L"LeftHeadNone");
		}
	}
	else if (m_bSuccessed == StateMoveHead::RIGHT)				// ������ ����Ű ������ ���
	{
		GetAnimator()->Play(L"RightHeadMove");

		// TODO : �� �ȼ� �Ÿ� Ȯ�� �� �ش� �Ÿ���ŭ �����̰� ���� �߰�
		pos.x += 150.f * fDT;									// ���������� �̵�

		m_fMovingTerm += fDT;
		if (m_fMovingTerm > 0.32)
		{
			m_bSuccessed = StateMoveHead::NONE;
			m_fMovingTerm = 0;
			GetAnimator()->Play(L"RightHeadNone");
		}
	}

	SetPos(pos);
}

bool CPlayerHead::GetAcctive()
{
	return m_bAcctive;
}
