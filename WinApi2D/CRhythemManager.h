#pragma once
class CRhythemManager
{
	SINGLETON(CRhythemManager);

private:
	float m_fOneBit;		// 한 비트 당 시간
	float m_fAccTime;		// 누적 시간
	float m_fHitTime;		// 눌렀을 떄 시간

public:

	virtual void update();

	void Play(float oneBit, float hitTime);
	bool Success();
	bool IsMonsterMove();
};

