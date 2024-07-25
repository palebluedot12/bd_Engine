#include "ChickenSitDownState.h"
#include "ChickenScript.h"

void ChickenSitDownState::Enter(ChickenScript* chicken)
{
	chicken->GetAnimator()->PlayAnimation(L"LeftSit", true);
}

void ChickenSitDownState::Update(ChickenScript* chicken)
{
	chicken->GetMovement()->SetDirection(Vector2::Zero);
}

void ChickenSitDownState::Exit(ChickenScript* chicken)
{

}
