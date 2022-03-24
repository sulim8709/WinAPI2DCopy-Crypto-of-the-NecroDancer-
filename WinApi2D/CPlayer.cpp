#include "framework.h"
#include "CPlayer.h"
#include "CRhythemManager.h"
#include "CMissedText.h"
#include "CAnimation.h"
#include "CAnimator.h"

void CPlayer::CreateMissedText()
{

	CMissedText* pMissedText = new CMissedText;
	pMissedText->SetPos(fPoint(WINSIZEX / 2 - 20.f, WINSIZEY - 60.f));
	pMissedText->SetDir(fVec2(0, -1));
	pMissedText->SetName(L"Missed_Text");

	CreateObj(pMissedText, GROUP_GAMEOBJ::MISSED_TEXT);
}

CPlayer::CPlayer()
{
	m_bAcctive = false;
	CD2DImage* m_pImgHead = CResourceManager::getInst()->LoadD2DImage(L"PlayerHeadImg", L"texture\\Character\\player1_heads.png");
	CD2DImage* m_pImgBody = CResourceManager::getInst()->LoadD2DImage(L"PlayerBodyImg", L"texture\\Character\\player1_armor_body.png");
	
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"RightBodyNone", m_pImgBody, fPoint(0.f, 0.f), fPoint(48.f, 48.f), fPoint(48.0f, 0.f), 0.5f, 4);
	//GetAnimator()->CreateAnimation(L"RightHeadMove", m_pImgHead, fPoint(0.f, 0.f), fPoint(48.f, 48.f), fPoint(48.0f, 0.f), 0.5f, 4);
	GetAnimator()->CreateAnimation(L"RightBodyMove", m_pImgBody, fPoint(0.f, 0.f),	fPoint(48.f, 48.f),	fPoint(48.0f, 0.f), 0.5f, 4);

	//GetAnimator()->Play(L"RightHeadMove");
	GetAnimator()->Play(L"RightBodyNone");

	CAnimation* pAni;
	/*pAni = GetAnimator()->FindAnimation(L"RightHeadMove");
	pAni->GetFrame(1).fptOffset = fPoint(0.f, -20.f);
	pAni->GetFrame(2).fptOffset = fPoint(0.f, -10.f);*/

	pAni = GetAnimator()->FindAnimation(L"RightBodyMove");
	pAni->GetFrame(1).fptOffset = fPoint(0.f, -20.f);
	pAni->GetFrame(2).fptOffset = fPoint(0.f, -10.f);
}

CPlayer::~CPlayer()
{
}

CPlayer* CPlayer::Clone()
{
	return new CPlayer(*this);
}

void CPlayer::update()
{
	fPoint pos = GetPos();


	
	if (KeyDown(VK_UP))
	{
		if (CRhythemManager::getInst()->Success())			// 타이밍 맞게 눌렀을 때
		{
			if (false == m_bAcctive)
			{
				// TODO :: 위로 올라가는 행동 구현
				pos.y -= 50.f;
				//GetAnimator()->Play(L"RightHeadMove");
				GetAnimator()->Play(L"RightBodyMove");
				m_bAcctive = true;
			}
		}
		else												// 타이밍 틀리게 눌렀을 때
		{
			if (false == m_bAcctive)
			{
				CreateMissedText();
				m_bAcctive = true;
				// TODO :: 하트 오브젝트 가운데에서 빗나감 글씨 출력
			}
		}
	}
	else if (KeyDown(VK_DOWN))
	{
		if (CRhythemManager::getInst()->Success())			// 타이밍 맞게 눌렀을 때
		{
			if (false == m_bAcctive)
			{
				// TODO :: 위로 올라가는 행동 구현
				pos.y += 50.f;
				//GetAnimator()->Play(L"RightHeadMove");
				GetAnimator()->Play(L"RightBodyMove");
				m_bAcctive = true;
			}
		}
		else												// 타이밍 틀리게 눌렀을 때
		{
			if (false == m_bAcctive)
			{
				CreateMissedText();
				m_bAcctive = true;
				// TODO :: 하트 오브젝트 가운데에서 빗나감 글씨 출력
			}
		}
	}
	else if (KeyDown(VK_LEFT))
	{
		if (CRhythemManager::getInst()->Success())			// 타이밍 맞게 눌렀을 때
		{
			if (false == m_bAcctive)
			{
				// TODO :: 위로 올라가는 행동 구현
				pos.x -= 50.f;
				//GetAnimator()->Play(L"RightHeadMove");
				GetAnimator()->Play(L"RightBodyMove");
				m_bAcctive = true;
			}
		}
		else												// 타이밍 틀리게 눌렀을 때
		{
			if (false == m_bAcctive)
			{
				CreateMissedText();
				m_bAcctive = true;
				// TODO :: 하트 오브젝트 가운데에서 빗나감 글씨 출력
			}
		}
	}
	else if (KeyDown(VK_RIGHT))
	{
		if (CRhythemManager::getInst()->Success())			// 타이밍 맞게 눌렀을 때
		{
			if (false == m_bAcctive)
			{
				// TODO :: 위로 올라가는 행동 구현
				pos.x += 50.f;
				//GetAnimator()->Play(L"RightHeadMove");
				GetAnimator()->Play(L"RightBodyMove");
				m_bAcctive = true;
			}
		}
		else												// 타이밍 틀리게 눌렀을 때
		{
			if (false == m_bAcctive)
			{
				CreateMissedText();
				m_bAcctive = true;
				// TODO :: 하트 오브젝트 가운데에서 빗나감 글씨 출력
			}
		}
	}
	

	if (CRhythemManager::getInst()->OneBit())
	{
		m_bAcctive = false;
	}

	SetPos(pos);
}

bool CPlayer::GetAcctive()
{
	return m_bAcctive;
}

void CPlayer::render()
{
	component_render();
}

