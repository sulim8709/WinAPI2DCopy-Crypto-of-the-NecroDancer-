#include "framework.h"
#include "CPlayerBody.h"
#include "CAnimation.h"
#include "CAnimator.h"
#include "CRhythemManager.h"

CPlayerBody::CPlayerBody()
{
	m_bAcctive = false;
	m_bStateRight = true;
	CD2DImage* m_pImgBody = CResourceManager::getInst()->LoadD2DImage(L"PlayerBodyImg", L"texture\\Character\\player1_armor_body.png");
	SetName(L"Player_Body");
	SetScale(fPoint(48.f, 48.f));

	CreateAnimator();
	GetAnimator()->CreateAnimation(L"RightBodyMove", m_pImgBody, fPoint(0.f, 0.f), fPoint(48.f, 48.f), fPoint(48.0f, 0.f), 0.08f, 4, false);
	GetAnimator()->CreateAnimation(L"RightBodyNone", m_pImgBody, fPoint(0.f, 0.f), fPoint(48.f, 48.f), fPoint(48.0f, 0.f), 0.08f, 4, false);
	GetAnimator()->CreateAnimation(L"LeftBodyMove", m_pImgBody, fPoint(0.f, 0.f), fPoint(48.f, 48.f), fPoint(48.0f, 0.f), 0.08f, 4, true);
	GetAnimator()->CreateAnimation(L"LeftBodyNone", m_pImgBody, fPoint(0.f, 0.f), fPoint(48.f, 48.f), fPoint(48.0f, 0.f), 0.08f, 4, true);

	CAnimation* pAni;
	pAni = GetAnimator()->FindAnimation(L"RightBodyMove");	// ���� ���������� ������ �� ������ ����
	pAni->GetFrame(1).fptOffset = fPoint(0.f, -15.f);
	pAni->GetFrame(2).fptOffset = fPoint(0.f, -5.f);

	pAni = GetAnimator()->FindAnimation(L"LeftBodyMove");	// ���� �������� ������ �� ������ ����
	pAni->GetFrame(1).fptOffset = fPoint(0.f, -15.f);
	pAni->GetFrame(2).fptOffset = fPoint(0.f, -5.f);

	GetAnimator()->Play(L"RightBodyNone");

}

CPlayerBody::~CPlayerBody()
{
}

CPlayerBody* CPlayerBody::Clone()
{
	return new CPlayerBody(*this);
}

void CPlayerBody::render()
{
	component_render();
}

void CPlayerBody::update()
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

void CPlayerBody::update_Move()
{
	if (KeyDown(VK_UP))
	{
		if (CRhythemManager::getInst()->Success())			// Ÿ�̹� �°� ������ ��
		{
			if (false == m_bAcctive)
			{
				m_bAcctive = true;
				m_bSuccessed = StateMoveBody::UP;
			}
		}
		else												// Ÿ�̹� Ʋ���� ������ ��
		{
			if (false == m_bAcctive)
			{
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
				m_bSuccessed = StateMoveBody::DOWN;
			}
		}
		else												// Ÿ�̹� Ʋ���� ������ ��
		{
			if (false == m_bAcctive)
			{
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
				m_bSuccessed = StateMoveBody::LEFT;
				m_bStateRight = false;
			}
		}
		else												// Ÿ�̹� Ʋ���� ������ ��
		{
			if (false == m_bAcctive)
			{
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
				m_bSuccessed = StateMoveBody::RIGHT;
				m_bStateRight = true;
			}
		}
		else												// Ÿ�̹� Ʋ���� ������ ��
		{
			if (false == m_bAcctive)
			{
				m_bAcctive = true;
			}
		}
	}
}

void CPlayerBody::update_Ani()
{
	fPoint pos = GetPos();

	if (m_bSuccessed == StateMoveBody::UP)
	{
		if (m_bStateRight)				
			GetAnimator()->Play(L"RightBodyMove");
		else
			GetAnimator()->Play(L"LeftBodyMove");

		// TODO : �� �ȼ� �Ÿ� Ȯ�� �� �ش� �Ÿ���ŭ �����̰� ���� �߰�
		pos.y -= 150.f * fDT;

		m_fMovingTerm += fDT;
		if (m_fMovingTerm > 0.32)		
		{
			m_bSuccessed = StateMoveBody::NONE;
			m_fMovingTerm = 0;

			if (m_bStateRight)		
				GetAnimator()->Play(L"RightBodyNone");
			else
				GetAnimator()->Play(L"LeftBodyNone");
		}
	}
	else if (m_bSuccessed == StateMoveBody::DOWN)
	{
		if (m_bStateRight)				
			GetAnimator()->Play(L"RightBodyMove");
		else
			GetAnimator()->Play(L"LeftBodyMove");

		// TODO : �� �ȼ� �Ÿ� Ȯ�� �� �ش� �Ÿ���ŭ �����̰� ���� �߰�
		pos.y += 150.f * fDT;

		m_fMovingTerm += fDT;
		if (m_fMovingTerm > 0.32)
		{
			m_bSuccessed = StateMoveBody::NONE;
			m_fMovingTerm = 0;

			if (m_bStateRight)			
				GetAnimator()->Play(L"RightBodyNone");
			else
				GetAnimator()->Play(L"LeftBodyNone");
		}
	}
	else if (m_bSuccessed == StateMoveBody::LEFT)
	{
		GetAnimator()->Play(L"LeftBodyMove");

		// TODO : �� �ȼ� �Ÿ� Ȯ�� �� �ش� �Ÿ���ŭ �����̰� ���� �߰�
		pos.x -= 150.f * fDT;

		m_fMovingTerm += fDT;
		if (m_fMovingTerm > 0.32)
		{
			m_bSuccessed = StateMoveBody::NONE;
			m_fMovingTerm = 0;
			GetAnimator()->Play(L"LeftBodyNone");
		}
	}
	else if (m_bSuccessed == StateMoveBody::RIGHT)
	{
		GetAnimator()->Play(L"RightBodyMove");

		// TODO : �� �ȼ� �Ÿ� Ȯ�� �� �ش� �Ÿ���ŭ �����̰� ���� �߰�
		pos.x += 150.f * fDT;

		m_fMovingTerm += fDT;
		if (m_fMovingTerm > 0.32)
		{
			m_bSuccessed = StateMoveBody::NONE;
			m_fMovingTerm = 0;
			GetAnimator()->Play(L"RightBodyNone");
		}
	}

	SetPos(pos);
}

bool CPlayerBody::GetAcctive()
{
	return m_bAcctive;
}
