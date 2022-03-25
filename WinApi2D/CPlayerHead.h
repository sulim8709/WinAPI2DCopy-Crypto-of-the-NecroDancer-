#pragma once
#include "CGameObject.h"

enum class StateMoveHead
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT,

};

class CPlayerHead : public CGameObject
{
private:
	void CreateMissedText();
	bool m_bAcctive;
	StateMoveHead m_bSuccessed;
	float m_fMovingTerm;
	bool m_bStateRight;

public:
	CPlayerHead();
	virtual ~CPlayerHead();

	virtual CPlayerHead* Clone();

	virtual void render();

	virtual void update();

	void update_Move();

	void update_Ani();

	bool GetAcctive();
};

