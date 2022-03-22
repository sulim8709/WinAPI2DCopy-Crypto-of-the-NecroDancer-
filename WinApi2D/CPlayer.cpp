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
	if (CRhythemManager::getInst()->Success())			// Ÿ�̹� �°� ������ ��
	{
		if (KeyDown(VK_UP))
		{
			// TODO :: ���� �ö󰡴� �ൿ ����
		}
	}
	else												// Ÿ�̹� Ʋ���� ������ ��
	{
		
		CreateMissedText();
		// TODO :: ��Ʈ ������Ʈ ������� ������ �۾� ���
	}
}
