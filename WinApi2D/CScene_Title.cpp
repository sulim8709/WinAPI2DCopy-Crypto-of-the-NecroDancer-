#include "framework.h"
#include "CScene_Title.h"
#include "CImageObject.h"
#include "CButtonUI.h"
#include "CBackGround.h"
#include "CImageButton.h"

void ClickStartButton(DWORD_PTR, DWORD_PTR)
{
	ChangeScn(GROUP_SCENE::STAGE_01);
	CSoundManager::getInst()->Stop(L"TitleBGM");
}

void ClickToolButton(DWORD_PTR, DWORD_PTR)
{
	ChangeScn(GROUP_SCENE::TOOL);
	CSoundManager::getInst()->Stop(L"TitleBGM");
}

CScene_Title::CScene_Title()
{
}

CScene_Title::~CScene_Title()
{
}

void CScene_Title::update()
{

	if (KeyDown(VK_RETURN))
	{
		ChangeScn(GROUP_SCENE::STAGE_01);
		CSoundManager::getInst()->Stop(L"TitleBGM");
	}

	if (KeyDown(VK_TAB))
	{
		ChangeScn(GROUP_SCENE::TOOL);
		CSoundManager::getInst()->Stop(L"TitleBGM");
	}
}


void CScene_Title::Enter()
{
	// Title BGM
	CSoundManager::getInst()->AddSound(L"TitleBGM", L"sound\\Title.ogg", false);
	CSoundManager::getInst()->Play(L"TitleBGM");

	//CD2DImage* m_pTitleImage = CResourceManager::getInst()->LoadD2DImage(L"TitleImage", L"texture\\title.png");
	
	// Title ????
	CBackGround* m_pTitleImage = new CBackGround;
	m_pTitleImage->Load(L"TitleImage", L"texture\\Title\\mainmenu.png");
	m_pTitleImage->SetScale(fPoint(WINSIZEX, WINSIZEY));
	AddObject(m_pTitleImage, GROUP_GAMEOBJ::BACKGROUND);

	CImageButton* m_pToolButton = new CImageButton;
	m_pToolButton->SetPos(fPoint(WINSIZEX / 2 - 100.f, WINSIZEY - 200.f));
	m_pToolButton->SetScale(fPoint(200, 100));
	m_pToolButton->SetText(L"Tool Button");
	m_pToolButton->SetClickedCallBack(ClickToolButton, 0, 0);
	AddObject(m_pToolButton, GROUP_GAMEOBJ::UI);
	
	CImageButton* m_pStartButton = new CImageButton;
	m_pStartButton->SetPos(fPoint(0.f, 0.f));
	m_pStartButton->SetScale(fPoint(WINSIZEX, WINSIZEY / 2.f));
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
