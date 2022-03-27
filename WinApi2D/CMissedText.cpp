#include "framework.h"
#include "CMissedText.h"
#include "CRhythemManager.h"

CMissedText::CMissedText()
{
	m_pImg = CResourceManager::getInst()->LoadD2DImage(L"Missed", L"texture\\Text\\TEMP_missed.png");
	SetName(L"Missed");
	SetScale(fPoint(36, 13));
	m_fvDir = fVec2(0, 0);
}

CMissedText::~CMissedText()
{
}

CMissedText* CMissedText::Clone()
{
	return new CMissedText(*this);
}

void CMissedText::update()
{
		fPoint pos = GetPos();

		pos.x += m_fSpeed * m_fvDir.x * fDT;
		pos.y += m_fSpeed * m_fvDir.y * fDT;

		SetPos(pos);

		if (pos.y < WINSIZEY - 150.f)
			DeleteObj(this);
}

void CMissedText::render()
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

void CMissedText::SetDir(fVec2 vec)
{
	m_fvDir = vec.Normalize();
}

void CMissedText::Load(const wstring& strKey, const wstring& strRelativePath)
{
	m_pImg = CResourceManager::getInst()->LoadD2DImage(strKey, strRelativePath);
}
