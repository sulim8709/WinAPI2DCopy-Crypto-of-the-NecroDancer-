#include "framework.h"
#include "CScene_Stage_01.h"

#include "CGameObject.h"
#include "CHeartObject.h"
#include "CBeatNode.h"
#include "CRhythemManager.h"
#include "CPlayerHead.h"
#include "CPlayerBody.h"

#include "CD2DImage.h"
#include "CSound.h"


CScene_Stage_01::CScene_Stage_01()
{
	
}

CScene_Stage_01::~CScene_Stage_01()
{
}

void CScene_Stage_01::update()
{
	CScene::update();
}

void CScene_Stage_01::Enter()
{
	CSoundManager::getInst()->AddSound(L"Stage01BGM", L"sound\\stage\\zone1_1.ogg", false);
	CSoundManager::getInst()->Play(L"Stage01BGM");

	CRhythemManager::getInst()->Play(1.f, 0.3f);


	// TEMP Heart Ãß°¡
	CHeartObject* pHeartObject = new CHeartObject;
	pHeartObject->SetPos(fPoint(WINSIZEX / 2, WINSIZEY - 60.f));
	pHeartObject->SetScale(fPoint(123.f, 156.f));
	AddObject(pHeartObject, GROUP_GAMEOBJ::HEART);


	


	CPlayerHead* pPlayerHead = new CPlayerHead;
	pPlayerHead->SetPos(fPoint(500.f, 500.f));
	AddObject(pPlayerHead, GROUP_GAMEOBJ::PLAYER);
	CPlayerBody* pPlayerBody = new CPlayerBody;
	pPlayerBody->SetPos(fPoint(500.f, 500.f));
	AddObject(pPlayerBody, GROUP_GAMEOBJ::PLAYER);

	CRhythemManager::getInst()->render();
}

void CScene_Stage_01::Exit()
{
	DeleteAll();

}
