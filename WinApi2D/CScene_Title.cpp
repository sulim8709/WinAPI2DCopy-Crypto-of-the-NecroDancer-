#include "framework.h"
#include "CScene_Title.h"
#include "CImageObject.h"
#include "CButtonUI.h"
#include "CBackGround.h"
#include "CImageButton.h"

void ClickStartButton(DWORD_PTR, DWORD_PTR)
{
	ChangeScn(GROUP_SCENE::TOOL);
}

void ClickExitButton(DWORD_PTR, DWORD_PTR)
{
	PostQuitMessage(0);
}

void CScene_Title::Enter()
{
	//CD2DImage* m_pTitleImage = CResourceManager::getInst()->LoadD2DImage(L"TitleImage", L"texture\\title.png");
	CBackGround* m_pTitleImage = new CBackGround;
	m_pTitleImage->Load(L"TitleImage", L"texture\\Title\\mainmenu.png");
	m_pTitleImage->SetScale(fPoint(WINSIZEX, WINSIZEY));
	AddObject(m_pTitleImage, GROUP_GAMEOBJ::BACKGROUND);

	CButtonUI* m_pStartButton = new CButtonUI;
	m_pStartButton->SetPos(fPoint(0.f, 0.f));
	m_pStartButton->SetScale(fPoint(WINSIZEX, WINSIZEY));
	m_pStartButton->SetClickedCallBack(ClickStartButton, 0, 0);
	AddObject(m_pStartButton, GROUP_GAMEOBJ::UI);


	CImageObject* m_pContinueButton = new CImageObject;
	m_pContinueButton->Load(L"ContinueImage", L"texture\\Title\\continue.png");
	m_pContinueButton->SetPos(fPoint(WINSIZEX / 2.f - 250.f, WINSIZEY - 50.f));
	m_pContinueButton->SetScale(fPoint(500, 40));
	AddObject(m_pContinueButton, GROUP_GAMEOBJ::UI);
}

void CScene_Title::Exit()
{
	DeleteAll();
}
