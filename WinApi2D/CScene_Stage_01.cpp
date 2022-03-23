#include "framework.h"
#include "CScene_Stage_01.h"

#include "CGameObject.h"
#include "CHeartObject.h"
#include "CBeatNode.h"
#include "CRhythemManager.h"
#include "CPlayer.h"

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
	CRhythemManager::getInst()->Play(2.f, 0.5f);


	// TEMP Heart Ãß°¡
	CHeartObject* pHeartObject = new CHeartObject;
	pHeartObject->SetPos(fPoint(WINSIZEX / 2 - 20.f, WINSIZEY - 60.f));
	pHeartObject->SetScale(fPoint(123.f, 156.f));
	AddObject(pHeartObject, GROUP_GAMEOBJ::HEART);

	CPlayer* pPlayer	 = new CPlayer;
	pPlayer->SetPos(fPoint(500, 500));
	AddObject(pPlayer, GROUP_GAMEOBJ::PLAYER);

	CRhythemManager::getInst()->render();
}

void CScene_Stage_01::Exit()
{
	DeleteAll();

}
