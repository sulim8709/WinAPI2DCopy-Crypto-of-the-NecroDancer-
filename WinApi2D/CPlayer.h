#pragma once
#include "CGameObject.h"
class CPlayer : public CGameObject
{
private:
	CD2DImage* m_pImgHead;
	CD2DImage* m_pImgBody;

	void CreateMissedText();

public:
	CPlayer();
	virtual ~CPlayer();

	virtual CPlayer* Clone();

	virtual void render();

	virtual void update();

};

