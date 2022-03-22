#pragma once
#include "CGameObject.h"
class CPlayer : public CGameObject
{
private:
	CD2DImage* m_pImg;

	void CreateMissedText();

public:
	CPlayer();
	virtual ~CPlayer();

	virtual void render();

	virtual void update();

};

