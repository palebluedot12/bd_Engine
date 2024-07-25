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
	Vector2 playerPos = chicken->GetPlayer()->GetComponent<Transform>()->GetPosition();
	Vector2 chickenPos = chicken->GetOwner()->GetComponent<Transform>()->GetPosition();
	float distance = (playerPos - chickenPos).Length();

}

void ChickenAttackState::Exit(ChickenScript* chicken)
{
}
