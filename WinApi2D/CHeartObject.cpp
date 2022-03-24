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
	CBeatNode* pBeatNode1 = new CBeatNode;
	pBeatNode1->SetPos(fPoint(0, WINSIZEY - 80.f));
	pBeatNode1->SetDir(fVec2(1, 0));
	pBeatNode1->SetName(L"BeatNode1_HeartBeat");

	CBeatNode* pBeatNode2 = new CBeatNode;
	pBeatNode2->SetPos(fPoint(WINSIZEX, WINSIZEY - 80.f));
	pBeatNode2->SetDir(fVec2(-1, 0));
	pBeatNode1->SetName(L"BeatNode2_HeartBeat");


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
	GetAnimator()->CreateAnimation(L"HeartBeat", m_pImg, fPoint(0.f, 0.f), fPoint(82.f, 104.f), fPoint(81.f, 0.f), HeartSmallTime, 2, false);

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


