#include "framework.h"
#include "CPlayer.h"
#include "CRhythemManager.h"
#include "CMissedText.h"
#include "CAnimation.h"
#include "CAnimator.h"

void CPlayer::CreateMissedText()
{

	CMissedText* pMissedText = new CMissedText;
	pMissedText->SetPos(fPoint(WINSIZEX / 2 - 41.f, WINSIZEY - 60.f));
	pMissedText->SetDir(fVec2(0, -1));
	pMissedText->SetName(L"Missed_Text");

	CreateObj(pMissedText, GROUP_GAMEOBJ::MISSED_TEXT);
}

CPlayer::CPlayer()
{
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

	if (CRhythemManager::getInst()->Success())			// Ÿ�̹� �°� ������ ��
	{
		if (KeyDown(VK_UP))
		{

			// TODO :: ���� �ö󰡴� �ൿ ����
			pos.y -= 50.f;
			//GetAnimator()->Play(L"RightHeadMove");
			GetAnimator()->Play(L"RightBodyMove");
		}
		else if (KeyDown(VK_DOWN))
		{
			pos.y += 50.f;
				//GetAnimator()->Play(L"RightHeadMove");
				GetAnimator()->Play(L"RightBodyMove");
		}

	}
	else												// Ÿ�̹� Ʋ���� ������ ��
	{
		CreateMissedText();
		// TODO :: ��Ʈ ������Ʈ ������� ������ �۾� ���
	};
	SetPos(pos);

}


void CPlayer::render()
{
	component_render();
}

