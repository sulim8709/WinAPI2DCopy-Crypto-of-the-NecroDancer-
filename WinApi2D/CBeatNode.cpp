#include "framework.h"
#include "CBeatNode.h"
#include "CCollider.h"
#include "CD2DImage.h"

CBeatNode::CBeatNode()
{
	m_pImg = CResourceManager::getInst()->LoadD2DImage(L"NodeGreenTex", L"texture\\gui\\TEMP_beat_marker_green.png");
	SetName(L"NodeGreen");
	SetScale(fPoint(6.f, 32.f));
	m_fvDir = fVec2(0, 0);

	//GetCollider()->SetScale(fPoint(120.f, 120.f));
	//CreateCollider();


	
}

CBeatNode::~CBeatNode()
{
}

CBeatNode* CBeatNode::Clone()
{
	return new CBeatNode(*this);
}

void CBeatNode::render()
{
	fPoint pos = GetPos();
	fPoint scale = GetScale();
	pos = CCameraManager::getInst()->GetRenderPos(pos);


	component_render();
}

void CBeatNode::update()
{
	fPoint pos = GetPos();

	pos.x += m_fSpeed * m_fvDir.x * fDT;
	pos.y += m_fSpeed * m_fvDir.y * fDT;

	SetPos(pos);

	if (pos.x > WINSIZEX / 2 - 38.f)
		DeleteObj(this);
}

void CBeatNode::SetDir(fVec2 vec)
{
	m_fvDir = vec.normalize();
}

void CBeatNode::SetDir(float theta)
{
	m_fvDir.x = (float)cos(theta);
	m_fvDir.y = (float)sin(theta);
}


