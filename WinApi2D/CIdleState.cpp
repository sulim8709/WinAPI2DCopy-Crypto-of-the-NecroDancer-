#include "framework.h"
#include "CIdleState.h"
#include "CMonster.h"

CIdleState::CIdleState(STATE_MON state)
	: CState(state)
{
}

CIdleState::~CIdleState()
{
}

void CIdleState::update()
{
	/*CPlayer* pPlayer = CPlayer::GetPlayer();
	fPoint fptPlayerPos = pPlayer->GetPos();

	CMonster* pMonster = GetMonster();
	fPoint fptMonsterPos = pMonster->GetPos();

	fVec2 fvDiff = fptPlayerPos - fptMonsterPos;
	float fLen = fvDiff.Length();
	if (fLen < pMonster->GetMonInfo().fRecogRange)
	{
		ChangeAIState(GetOwnerAI(), STATE_MON::TRACE);
	}*/

}

void CIdleState::Enter()
{
}

void CIdleState::Exit()
{
}
