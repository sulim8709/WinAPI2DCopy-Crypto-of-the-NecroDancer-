#include "framework.h"
#include "CImageObject.h"


CImageObject::CImageObject()
{
    m_pImg = nullptr;
}

CImageObject::~CImageObject()
{
}

CImageObject* CImageObject::Clone()
{
    return nullptr;
}

void CImageObject::update()
{
}

void CImageObject::render()
{
    if (nullptr == m_pImg)
    {
        return;
    }
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

void CImageObject::Load(const wstring& strKey, const wstring& strRelativePath)
{
    m_pImg = CResourceManager::getInst()->LoadD2DImage(strKey, strRelativePath);
}
