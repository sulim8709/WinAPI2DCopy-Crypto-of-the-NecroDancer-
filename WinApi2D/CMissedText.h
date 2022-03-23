#pragma once
#include "CGameObject.h"
class CMissedText : public CGameObject
{
private:
	CD2DImage* m_pImg;
	fVec2 m_fvDir;
	float m_fSpeed = 100.f;

public:
	CMissedText();
	virtual ~CMissedText();

	virtual CMissedText* Clone();
	virtual void update();
	virtual void render();

	void SetDir(fVec2 vec);
	
	

	void Load(const wstring& strKey, const wstring& strRelativePath);
};

