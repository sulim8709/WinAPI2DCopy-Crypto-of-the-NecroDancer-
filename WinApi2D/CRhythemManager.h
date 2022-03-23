#pragma once
class CRhythemManager
{
	SINGLETON(CRhythemManager);

private:
	double m_dOneBit;		// �� ��Ʈ �� �ð�
	double m_dAccTime;		// ���� �ð�
	double m_dHitTime;		// ������ �� �ð�
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

