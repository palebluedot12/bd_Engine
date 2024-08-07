#include "ChickenChaseState.h"
#include "ChickenScript.h"


void ChickenChaseState::Enter(ChickenScript* chicken)
{
}

void ChickenChaseState::Update(ChickenScript* chicken)
{
    Vector2 playerPos = chicken->GetPlayer()->GetComponent<Transform>()->GetPosition();
    Vector2 chickenPos = chicken->GetOwner()->GetComponent<Transform>()->GetPosition();
    Vector2 direction = (playerPos - chickenPos).Normalized();
    float distance = (playerPos - chickenPos).Length();

    chicken->GetMovement()->SetDirection(direction);

    const std::wstring& currentAnim = chicken->GetAnimator()->GetActiveAnimationName();
    if (direction.x > 0)
    {
        if (currentAnim != L"RightWalk")
            chicken->GetAnimator()->PlayAnimation(L"RightWalk", true);
    }
    else
    {
        if (currentAnim != L"LeftWalk")
            chicken->GetAnimator()->PlayAnimation(L"LeftWalk", true);
    }

    if (distance <= 50.0f)
    {
        SetState(chicken, ChickenScript::State::Attack);
    }

    else if (distance > 300.0f)
    {
        SetState(chicken, ChickenScript::State::SitDown);
    }
}

void ChickenChaseState::Exit(ChickenScript* chicken)
{
    int a = 0;

}
