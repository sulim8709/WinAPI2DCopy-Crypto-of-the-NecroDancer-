#include "framework.h"
#include "CRhythemManager.h"

CRhythemManager::CRhythemManager()
{

}

CRhythemManager::~CRhythemManager()
{

}

void CRhythemManager::update()
{
    m_dAccTime += DT;

    if (m_dAccTime > m_dOneBit)
    {
        m_dAccTime -= m_dOneBit;
        m_bAbsolute = false;
        m_bOneBit = true;
    }
    else
    {
        m_bOneBit = false;
    }
}

void CRhythemManager::render()
{
    UINT BAR_SIZE = WINSIZEX;
    float thick = m_dAccTime / m_dOneBit;
    float minTiming = (m_dHalfBit - m_dHitTime) / m_dOneBit;
    float maxTiming = (m_dHalfBit + m_dHitTime) / m_dOneBit;

    CRenderManager::getInst()->RenderRectangle(0, 0, BAR_SIZE, 30);
    CRenderManager::getInst()->RenderFillRectangle(BAR_SIZE * minTiming, 0, BAR_SIZE * maxTiming, 30, RGB(0, 255, 0));
    CRenderManager::getInst()->RenderFillRectangle(BAR_SIZE / 2.f, 0, BAR_SIZE / 2.f + 1, 30);
    CRenderManager::getInst()->RenderFillRectangle(BAR_SIZE * thick, 0, BAR_SIZE * thick + 1, 30);
}

void CRhythemManager::Play(float oneBit, float hitTime)
{
    m_dOneBit = oneBit;
    m_dHalfBit = oneBit / 2.f;
    m_dHitTime = hitTime;
}

bool CRhythemManager::Success()
{
    if (m_dAccTime > m_dHalfBit - m_dHitTime &&
        m_dAccTime < m_dHalfBit + m_dHitTime)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CRhythemManager::Absolute()
{
    if (m_dAccTime > m_dHalfBit && false == m_bAbsolute)
    {
        m_bAbsolute = true;
        return true;
    }
    else
    {
        return false;
    }
}

float CRhythemManager::GetAccTime()
{
    return m_dAccTime;
}

bool CRhythemManager::OneBit()
{
    return m_bOneBit;
}
