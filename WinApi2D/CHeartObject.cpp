#include "framework.h"
#include "CHeartObject.h"
#include "CBeatNode.h"
#include "CCollider.h"
#include "CD2DImage.h"
#include "CAnimator.h"
#include "CAnimation.h"
#include "CRhythemManager.h"

void CHeartObject::CreateBeatNode()
{
	// 1/4 지점
	CBeatNode* pBeatNode1 = new CBeatNode;
	pBeatNode1->SetPos(fPoint(0, WINSIZEY - 80.f));
	pBeatNode1->SetDir(fVec2(1, 0));
	pBeatNode1->SetName(L"BeatNode1_HeartBeat");

	CBeatNode* pBeatNode2 = new CBeatNode;
	pBeatNode2->SetPos(fPoint(WINSIZEX, WINSIZEY - 80.f));
	pBeatNode2->SetDir(fVec2(-1, 0));
	pBeatNode2->SetName(L"BeatNode2_HeartBeat");

	// 2/4 지점
	CBeatNode* pBeatNode3 = new CBeatNode;
	pBeatNode3->SetPos(fPoint(((WINSIZEX) / 8) + 15.f, WINSIZEY - 80.f));
	pBeatNode3->SetDir(fVec2(1, 0));
	pBeatNode3->SetName(L"BeatNode3_HeartBeat");

	CBeatNode* pBeatNode4 = new CBeatNode;
	pBeatNode4->SetPos(fPoint((WINSIZEX / 8) * 7 - 15.f, WINSIZEY - 80.f));
	pBeatNode4->SetDir(fVec2(-1, 0));
	pBeatNode4->SetName(L"BeatNode4_HeartBeat");

	// 3/4 지점
	CBeatNode* pBeatNode5 = new CBeatNode;
	pBeatNode5->SetPos(fPoint((WINSIZEX / 8) * 2 + 30.f, WINSIZEY - 80.f));
	pBeatNode5->SetDir(fVec2(1, 0));
	pBeatNode5->SetName(L"BeatNode5_HeartBeat");

	CBeatNode* pBeatNode6 = new CBeatNode;
	pBeatNode6->SetPos(fPoint((WINSIZEX / 8) * 6 - 30.f, WINSIZEY - 80.f));
	pBeatNode6->SetDir(fVec2(-1, 0));
	pBeatNode6->SetName(L"BeatNode6_HeartBeat");

	// 4/4 지점
	CBeatNode* pBeatNode7 = new CBeatNode;
	pBeatNode7->SetPos(fPoint((WINSIZEX / 8) * 3 + 45.f, WINSIZEY - 80.f));
	pBeatNode7->SetDir(fVec2(1, 0));
	pBeatNode7->SetName(L"BeatNode7_HeartBeat");

	CBeatNode* pBeatNode8 = new CBeatNode;
	pBeatNode8->SetPos(fPoint((WINSIZEX / 8) * 5 - 45.f, WINSIZEY - 80.f));
	pBeatNode8->SetDir(fVec2(-1, 0));
	pBeatNode8->SetName(L"BeatNode8_HeartBeat");

	

	CreateObj(pBeatNode3, GROUP_GAMEOBJ::NODE);
	CreateObj(pBeatNode4, GROUP_GAMEOBJ::NODE);
	CreateObj(pBeatNode5, GROUP_GAMEOBJ::NODE);
	CreateObj(pBeatNode6, GROUP_GAMEOBJ::NODE);
	CreateObj(pBeatNode7, GROUP_GAMEOBJ::NODE);
	CreateObj(pBeatNode8, GROUP_GAMEOBJ::NODE);
	
	CreateObj(pBeatNode1, GROUP_GAMEOBJ::NODE);
	CreateObj(pBeatNode2, GROUP_GAMEOBJ::NODE);
	
}

CHeartObject::CHeartObject()
{
	m_pImg = CResourceManager::getInst()->LoadD2DImage(L"HeartBeatTex", L"texture\\gui\\TEMP_beat_heart.png");
	m_count = 0;

	float HeartSmallTime = CRhythemManager::getInst()->GetTiming();
	float HeartBigTime = CRhythemManager::getInst()->GetFalseTiming();

	SetName(L"Heart");
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"HeartBeat", m_pImg, fPoint(0.f, 0.f), fPoint(82.f, 104.f), fPoint(82.f, 0.f), HeartSmallTime, 2, false);

	CAnimation* pAni;
	pAni = GetAnimator()->FindAnimation(L"HeartBeat");
	pAni->GetFrame(1).fDuration = HeartBigTime;


	GetAnimator()->Play(L"HeartBeat");
}

CHeartObject::~CHeartObject()
{
}

CHeartObject* CHeartObject::Clone()
{
	return new CHeartObject(*this);
}

void CHeartObject::render()
{
	fPoint pos = GetPos();
	fPoint scale = GetScale();
	pos = CCameraManager::getInst()->GetRenderPos(pos);

	component_render();
}

void CHeartObject::update()
{
	if (nullptr != GetAnimator())
		GetAnimator()->update();

	CAnimation* pAni;
	pAni = GetAnimator()->FindAnimation(L"HeartBeat");

	if (CRhythemManager::getInst()->OneBit())
	{
		CreateBeatNode();
	}
}



int CHeartObject::GetCount()
{
	return m_count;
}

void CHeartObject::SetCount(int count)
{
	m_count = count;
}


