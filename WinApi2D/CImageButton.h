#pragma once
#include "CButtonUI.h"

class CD2DImage;

class CImageButton : public CButtonUI
{
private:
	wstring m_strText;
	CD2DImage* m_pImg;

public:
	CImageButton();
	virtual ~CImageButton();

	virtual void render();

	void SetText(const wstring& text);
	void Load(const wstring& strKey, const wstring& strRelativePath);
};

