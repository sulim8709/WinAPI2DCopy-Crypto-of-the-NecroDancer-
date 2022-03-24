#include "framework.h"

#include "CBeatNode.h"
#include "CPlayer.h"

#include "CCollider.h"
#include "CD2DImage.h"

CBeatNode::CBeatNode()
{
	m_pImg = CResourceManager::getInst()->LoadD2DImage(L"NodeGreenTex", L"texture\\gui\\TEMP_beat_marker.png");
	SetName(L"NodeGreen");
	SetScale(fPoint(12.f, 64.f));
	m_fvDir = fVec2(0, 0);

	float fTime = CRhythemManager::getInst()->GetHalfBit();
	m_fSpeed = (((WINSIZEX / 2.f) + 62.f ) / fTime) / 8;

}

CBeatNode::~CBeatNode()
{
}

CBeatNode* CBeatNode::Clone()
{
	return new CBeatNode(*this);
}

void CBeatNode::update()
{
	fPoint pos = GetPos();

	pos.x += m_fSpeed * m_fvDir.x * fDT;
	pos.y += m_fSpeed * m_fvDir.y * fDT;

	SetPos(pos);

	if (pos.x > WINSIZEX / 2 - 2.f && pos.x < WINSIZEX / 2 + 2.f)
		DeleteObj(this);

	
}

void CBeatNode::render()
{
	fPoint pos = GetPos();
	fPoint scale = GetScale();

	fPoint renderPos = CCameraManager::getInst()->GetRenderPos(pos);

	CRenderManager::getInst()->RenderImage(
		m_pImg,
		renderPos.x,
		renderPos.y,
		renderPos.x + scale.x,
		renderPos.y + scale.y
	);
}

void CBeatNode::SetDir(fVec2 vec)
{
	m_fvDir = vec.normalize();
}

void CBeatNode::Load(const wstring& strKey, const wstring& strRelativePath)
{
	m_pImg = CResourceManager::getInst()->LoadD2DImage(strKey, strRelativePath);
}



