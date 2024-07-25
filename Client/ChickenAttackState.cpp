#include "ChickenAttackState.h"
#include "ChickenScript.h"

void ChickenAttackState::Enter(ChickenScript* chicken)
{
	chicken->GetAnimator()->PlayAnimation(L"Attack", true);
	//chicken->GetAnimator()->GetCompleteEvent(L"Attack") = std::bind(&ChickenScript::OnAttackAnimationComplete, this);
}

void ChickenAttackState::Update(ChickenScript* chicken)
{
	chicken->GetMovement()->SetDirection(Vector2::Zero);

}

void ChickenAttackState::Exit(ChickenScript* chicken)
{
}
