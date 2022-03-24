#pragma once
#include "CGameObject.h"
class CPlayer : public CGameObject
{
private:

	void CreateMissedText();
	bool m_bAcctive;
public:
	CPlayer();
	virtual ~CPlayer();

	virtual CPlayer* Clone();

	virtual void render();

	virtual void update();

	bool GetAcctive();
	
};

