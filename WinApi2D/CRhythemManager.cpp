#include "framework.h"
#include "CRhythemManager.h"

CRhythemManager::CRhythemManager()
{
    m_fOneBit = 0;		
    m_fAccTime = 0;		
    m_fHitTime = 0;		
    m_fHalfBit = 0;
    m_bAbsolute = 0;
    m_bOneBit = 0;
}

CRhythemManager::~CRhythemManager()
{

}

void CRhythemManager::update()
{
    m_fAccTime += fDT;

    if (0 == m_fOneBit)
        m_fAccTime = 0;

    if (m_fAccTime > m_fOneBit)
    {
        m_fAccTime -= m_fOneBit;
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
    float thick = m_fAccTime / m_fOneBit;
    float minTiming = (m_fHalfBit - m_fHitTime) / m_fOneBit;
    float maxTiming = (m_fHalfBit + m_fHitTime) / m_fOneBit;

    CRenderManager::getInst()->RenderRectangle(0, 0, BAR_SIZE, 30);
    CRenderManager::getInst()->RenderFillRectangle(BAR_SIZE * minTiming, 0, BAR_SIZE * maxTiming, 30, RGB(0, 255, 0));
    CRenderManager::getInst()->RenderFillRectangle(BAR_SIZE / 2.f, 0, BAR_SIZE / 2.f + 1, 30);
    CRenderManager::getInst()->RenderFillRectangle(BAR_SIZE * thick, 0, BAR_SIZE * thick + 1, 30);
}

void CRhythemManager::Play(float oneBit, float hitTime)
{
    m_fOneBit = oneBit;
    m_fHalfBit = oneBit / 2.f;
    m_fHitTime = hitTime;
}

bool CRhythemManager::Success()
{
    if (m_fAccTime > m_fHalfBit - m_fHitTime &&
        m_fAccTime < m_fHalfBit + m_fHitTime)
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
    if (m_fAccTime > m_fHalfBit && false == m_bAbsolute)
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
    return m_fAccTime;
}

bool CRhythemManager::OneBit()
{
    return m_bOneBit;
}

float CRhythemManager::GetTiming()
{
    return m_fHitTime * 2;
}

float CRhythemManager::GetFalseTiming()
{
    return m_fOneBit - (m_fHitTime * 2);
}

float CRhythemManager::GetOnebit()
{
    return m_fOneBit;
}

float CRhythemManager::GetHalfBit()
{
    return m_fHalfBit;
}

