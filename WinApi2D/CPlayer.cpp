#include "framework.h"
#include "CPlayer.h"
#include "CRhythemManager.h"
#include "CMissedText.h"


void CPlayer::CreateMissedText()
{

	CMissedText* pMissedText = new CMissedText;
	pMissedText->SetPos(fPoint(WINSIZEX / 2 - 20.f, WINSIZEY - 60.f));
	pMissedText->SetDir(fVec2(0, 1));
	pMissedText->SetName(L"Missed_Text");

	CreateObj(pMissedText, GROUP_GAMEOBJ::MISSED_TEXT);
}

CPlayer::CPlayer()
{
	m_pImg = nullptr;
}

CPlayer::~CPlayer()
{
}

void CPlayer::render()
{
}

void CPlayer::update()
{
	if (CRhythemManager::getInst()->Success())			// 타이밍 맞게 눌렀을 때
	{
		if (KeyDown(VK_UP))
		{
			// TODO :: 위로 올라가는 행동 구현
		}
	}
	else												// 타이밍 틀리게 눌렀을 때
	{
		
		CreateMissedText();
		// TODO :: 하트 오브젝트 가운데에서 빗나감 글씨 출력
	}
}
