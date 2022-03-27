#pragma once
#include "CScene.h"

class CButtonUI;

class CScene_Title : public CScene
{
private:

public:
    CScene_Title();
    virtual ~CScene_Title();

    virtual void update();

    virtual void Enter();
    virtual void Exit();

};

