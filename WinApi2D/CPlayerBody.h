#pragma once
#include "CGameObject.h"

enum class StateMoveBody
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT,

};

class CPlayerBody : public CGameObject
{
private:
	bool m_bAcctive;
	StateMoveBody m_bSuccessed;
	float m_fMovingTerm;
	bool m_bStateRight;

public:
	CPlayerBody();
	virtual ~CPlayerBody();

	virtual CPlayerBody* Clone();

	virtual void render();

	virtual void update();

	void update_Move();

	void update_Ani();

	bool GetAcctive();
};

