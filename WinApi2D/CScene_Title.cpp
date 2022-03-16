#include "framework.h"
#include "CScene_Title.h"
#include "CBackGround.h"
#include "CButtonUI.h"

void ClickStartButton(DWORD_PTR, DWORD_PTR)
{
	ChangeScn(GROUP_SCENE::TOOL);
}

void CScene_Title::Enter()
{
	//CD2DImage* m_pTitleImage = CResourceManager::getInst()->LoadD2DImage(L"TitleImage", L"texture\\title.png");
	CBackGround* m_pTitleImage = new CBackGround;
	m_pTitleImage->Load(L"TitleImage", L"texture\\mainmenu.png");
	m_pTitleImage->SetPos(fPoint(0.f, 0.f));
	m_pTitleImage->SetScale(fPoint(0.f, 0.f));

	AddObject(m_pTitleImage, GROUP_GAMEOBJ::BACKGROUND);

	CButtonUI* m_pStartButton = new CButtonUI;
	m_pStartButton->SetScale(fPoint(100.f, 50.f));
	m_pStartButton->SetPos(fPoint(WINSIZEX / 2.f - 50.f, WINSIZEY - 300.f));
	AddObject(m_pStartButton, GROUP_GAMEOBJ::UI);

	CButtonUI* m_pExitButton = new CButtonUI;
	m_pStartButton->SetScale(fPoint(100.f, 50.f));
	m_pStartButton->SetPos(fPoint(WINSIZEX / 2.f - 50.f, WINSIZEY - 200.f));
	AddObject(m_pStartButton, GROUP_GAMEOBJ::UI);
}

void CScene_Title::Exit()
{
	DeleteAll();
}
