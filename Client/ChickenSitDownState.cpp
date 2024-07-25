#include "ChickenSitDownState.h"
#include "ChickenScript.h"

void ChickenSitDownState::Enter(ChickenScript* chicken)
{
	chicken->GetAnimator()->PlayAnimation(L"LeftSit", true);
}

void ChickenSitDownState::Update(ChickenScript* chicken)
{
	chicken->GetMovement()->SetDirection(Vector2::Zero);

    Vector2 playerPos = chicken->GetPlayer()->GetComponent<Transform>()->GetPosition();
    Vector2 chickenPos = chicken->GetOwner()->GetComponent<Transform>()->GetPosition();
    float distance = (playerPos - chickenPos).Length();

    if (distance <= 300.0f && distance > 50.0f)
    {
        SetState(chicken, ChickenScript::State::Chase);
    }
}

void ChickenSitDownState::Exit(ChickenScript* chicken)
{

}
