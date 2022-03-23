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
	m_fAccTime += fDT;
	
	if (m_fAccTime > m_fOneBit)
	{
		m_fAccTime -= m_fOneBit;
	}


}

void CRhythemManager::Play(float oneBit, float hitTime)
{
	m_fOneBit = oneBit;
	m_fHitTime = hitTime;
}

bool CRhythemManager::Success()
{
	if (m_fAccTime < m_fHitTime)
	{
		return true;
	}

	return false;
}

bool CRhythemManager::IsMonsterMove()
{
	if (m_fAccTime >= m_fOneBit)
	{
		return true;
	}
	return false;
}
