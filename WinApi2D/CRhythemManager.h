#pragma once
class CRhythemManager
{
	SINGLETON(CRhythemManager);

private:
	float m_fOneBit;		// �� ��Ʈ �� �ð�
	float m_fAccTime;		// ���� �ð�
	float m_fHitTime;		// ������ �� �ð�
	float m_fHalfBit;
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
	float GetTiming();
	float GetFalseTiming();
	float GetOnebit();
	float GetHalfBit();

};

