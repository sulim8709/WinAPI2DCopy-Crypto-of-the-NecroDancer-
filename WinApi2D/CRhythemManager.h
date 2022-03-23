#pragma once
class CRhythemManager
{
	SINGLETON(CRhythemManager);

private:
	float m_fOneBit;		// �� ��Ʈ �� �ð�
	float m_fAccTime;		// ���� �ð�
	float m_fHitTime;		// ������ �� �ð�

public:

	virtual void update();

	void Play(float oneBit, float hitTime);
	bool Success();
	bool IsMonsterMove();
};

