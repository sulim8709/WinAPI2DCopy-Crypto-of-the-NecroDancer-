#include "framework.h"
#include "CMissedText.h"

CMissedText::CMissedText()
{
	m_pImg = CResourceManager::getInst()->LoadD2DImage(L"Missed", L"texture\\Text\\TEMP_missed.png");
	SetName(L"Missed");

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

	if (pos.y < WINSIZEY - 100.f)
		DeleteObj(this);
}

void CMissedText::render()
{
	fPoint pos = GetPos();
	fPoint scale = GetScale();

	fPoint renderPos = CCameraManager::getInst()->GetRenderPos(pos);
	renderPos = pos + (renderPos - pos) / 5;    // 배경은 살짝 느리게 이동



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
	m_fvDir = vec.normalize();
}

void CMissedText::Load(const wstring& strKey, const wstring& strRelativePath)
{
	m_pImg = CResourceManager::getInst()->LoadD2DImage(strKey, strRelativePath);
}
