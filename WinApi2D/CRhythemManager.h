#pragma once
class CRhythemManager
{
	SINGLETON(CRhythemManager);

private:
	double m_dOneBit;		// 한 비트 당 시간
	double m_dAccTime;		// 누적 시간
	double m_dHitTime;		// 눌렀을 떄 시간
	double m_dHalfBit;
	bool m_bAbsolute;
	bool m_bOneBit;

public:

	virtual void update();
	void render();

	void Play(float oneBit, float hitTime);
	bool Success();
	bool Absolute();

	float GetAccTime();
	bool OneBit();
};

