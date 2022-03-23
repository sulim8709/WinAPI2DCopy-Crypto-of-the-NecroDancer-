#pragma once
#include "CGameObject.h"
class CPlayer : public CGameObject
{
private:

	void CreateMissedText();

public:
	CPlayer();
	virtual ~CPlayer();

	virtual CPlayer* Clone();

	virtual void render();

	virtual void update();

};

