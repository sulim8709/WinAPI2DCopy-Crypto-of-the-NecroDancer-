#pragma once
#include "CGameObject.h"

class CD2DImage;

class CHeartObject : public CGameObject
{
private:
	CD2DImage* m_pImg;
	int m_count;

	void CreateBeatNode();
public:
	CHeartObject();
	virtual ~CHeartObject();
	virtual CHeartObject* Clone();

	virtual void render();
	virtual void update();

	int GetCount();
	void SetCount(int count);

	//void OnCollisionEnter(CCollider* pOther);

};

