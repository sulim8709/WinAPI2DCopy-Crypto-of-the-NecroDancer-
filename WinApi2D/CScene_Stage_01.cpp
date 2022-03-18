#include "framework.h"
#include "CScene_Stage_01.h"

#include "CGameObject.h"
#include "CHeartObject.h"
#include "CBeatNode.h"

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
	// TEMP Heart Ãß°¡
	CHeartObject* pHeartObject = new CHeartObject;
	pHeartObject->SetPos(fPoint(WINSIZEX / 2 - 20.f, WINSIZEY - 60.f));
	pHeartObject->SetScale(fPoint(123.f, 156.f));
	AddObject(pHeartObject, GROUP_GAMEOBJ::HEART);



	//CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::HEART, GROUP_GAMEOBJ::NOTE);
}

void CScene_Stage_01::Exit()
{
	DeleteAll();

	//CCollisionManager::getInst()->Reset();
}
