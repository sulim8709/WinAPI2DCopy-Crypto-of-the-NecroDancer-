#pragma once
#include "CGameObject.h"
class CBeatNode : public CGameObject
{
private:
	CD2DImage* m_pImg;
	fVec2 m_fvDir;
	float m_fSpeed;




public:
	CBeatNode();
	virtual ~CBeatNode();
	virtual CBeatNode* Clone();

	virtual void render();
	virtual void update();

	void SetDir(fVec2 vec);

	void Load(const wstring& strKey, const wstring& strRelativePath);
};

