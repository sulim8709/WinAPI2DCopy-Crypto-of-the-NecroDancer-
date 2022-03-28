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
	pAni = GetAnimator()->FindAnimation(L"RightHeadMove");	// 머리가 오른쪽으로 움직일 때 오프셋 수정
	pAni->GetFrame(1).fptOffset = fPoint(0.f, -15.f);
	pAni->GetFrame(2).fptOffset = fPoint(0.f, -5.f);

	pAni = GetAnimator()->FindAnimation(L"LeftHeadMove");	// 머리가 왼쪽으로 움직일 때 오프셋 수정
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

	if (CRhythemManager::getInst()->OneBit()) // 1박자마다 행동 여부 False로 초기화
	{
		m_bAcctive = false;
	}
}

void CPlayerHead::update_Move()
{
	if (KeyDown(VK_UP))
	{
		if (CRhythemManager::getInst()->Success())			// 타이밍 맞게 눌렀을 때
		{
			if (false == m_bAcctive)
			{
				m_bAcctive = true;
				m_bSuccessed = StateMoveHead::UP;
			}
		}
		else												// 타이밍 틀리게 눌렀을 때
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
		if (CRhythemManager::getInst()->Success())			// 타이밍 맞게 눌렀을 때
		{
			if (false == m_bAcctive)
			{
				m_bAcctive = true;
				m_bSuccessed = StateMoveHead::DOWN;
			}
		}
		else												// 타이밍 틀리게 눌렀을 때
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
		if (CRhythemManager::getInst()->Success())			// 타이밍 맞게 눌렀을 때
		{
			if (false == m_bAcctive)
			{
				m_bAcctive = true;
				m_bSuccessed = StateMoveHead::LEFT;
				m_bStateRight = false;
			}
		}
		else												// 타이밍 틀리게 눌렀을 때
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
		if (CRhythemManager::getInst()->Success())			// 타이밍 맞게 눌렀을 때
		{
			if (false == m_bAcctive)
			{
				m_bAcctive = true;
				m_bSuccessed = StateMoveHead::RIGHT;
				m_bStateRight = true;
			}
		}
		else												// 타이밍 틀리게 눌렀을 때
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
		
	if (m_bSuccessed == StateMoveHead::UP)						// 위 방향키 눌렸을 경우
	{
		if (m_bStateRight)										// 현재 바라보고 있는 방향 확인
			GetAnimator()->Play(L"RightHeadMove");				// 오른쪽 머리 이동 재생
		else
			GetAnimator()->Play(L"LeftHeadMove");				// 왼쪽   머리 이동 재생

		// TODO : 맵 픽셀 거리 확인 후 해당 거리만큼 움직이게 조건 추가
		pos.y -= 150.f * fDT;									// 위로 이동

		m_fMovingTerm += fDT;									// 움직이는 텀 구하기 위한 시간 축적
		if (m_fMovingTerm > 0.32)								// 0.48초(애니메이터 시간) 초과 될 경우
		{
			m_bSuccessed = StateMoveHead::NONE;					// 상태 NONE으로 바꿈
			m_fMovingTerm = 0;									// 시간 0초로 초기화

			if (m_bStateRight)									// 현재 바라보고 있는 방향 확인
				GetAnimator()->Play(L"RightHeadNone");			// 오른쪽 머리 대기 재생
			else
				GetAnimator()->Play(L"LeftHeadNone");			// 왼쪽   머리 대기 재생
		}
	}
	else if (m_bSuccessed == StateMoveHead::DOWN)				// 아래 방향키 눌렸을 경우
	{
		if (m_bStateRight)									
			GetAnimator()->Play(L"RightHeadMove");			
		else
			GetAnimator()->Play(L"LeftHeadMove");			

		// TODO : 맵 픽셀 거리 확인 후 해당 거리만큼 움직이게 조건 추가
		pos.y += 150.f * fDT;									// 아래로 이동

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
	else if (m_bSuccessed == StateMoveHead::LEFT)				// 왼쪽 방향키 눌렸을 경우
	{
		GetAnimator()->Play(L"LeftHeadMove");				

		// TODO : 맵 픽셀 거리 확인 후 해당 거리만큼 움직이게 조건 추가
		pos.x -= 150.f * fDT;									// 왼쪽으로 이동

		m_fMovingTerm += fDT;
		if (m_fMovingTerm > 0.32)
		{
			m_bSuccessed = StateMoveHead::NONE;
			m_fMovingTerm = 0;
			GetAnimator()->Play(L"LeftHeadNone");
		}
	}
	else if (m_bSuccessed == StateMoveHead::RIGHT)				// 오른쪽 방향키 눌렸을 경우
	{
		GetAnimator()->Play(L"RightHeadMove");

		// TODO : 맵 픽셀 거리 확인 후 해당 거리만큼 움직이게 조건 추가
		pos.x += 150.f * fDT;									// 오른쪽으로 이동

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
