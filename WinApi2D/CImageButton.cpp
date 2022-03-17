#include "framework.h"
#include "CImageButton.h"

CImageButton::CImageButton()
{
	m_strText = L"";
	m_pImg = nullptr;
}

CImageButton::~CImageButton()
{
}

void CImageButton::render()
{
	if (nullptr != m_pImg)
	{
		CRenderManager::getInst()->RenderImage(
			m_pImg,
			GetPos().x,
			GetPos().y,
			GetPos().x + GetScale().x,
			GetPos().y + GetScale().y
		);
	}

	CRenderManager::getInst()->RenderText(m_strText,
		GetPos().x,
		GetPos().y,
		GetPos().x + GetScale().x,
		GetPos().y + GetScale().y,
		20.f,
		RGB(255, 255, 255)
	);
}

void CImageButton::SetText(const wstring& text)
{
	m_strText = text;
}

void CImageButton::Load(const wstring& strKey, const wstring& strRelativePath)
{
	m_pImg = CResourceManager::getInst()->LoadD2DImage(strKey, strRelativePath);
}
