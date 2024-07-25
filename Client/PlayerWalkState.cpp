#include "PlayerWalkState.h"
#include "PlayerScript.h"
#include "..\\bdEngine\\InputManager.h"
#include "..\\bdEngine\\Transform.h"
#include "..\\bdEngine\\Time.h"

void PlayerWalkState::Enter(PlayerScript* player)
{
    // 방향에 따른 애니메이션 설정
    if (Input::GetKey(eKeyCode::Right))
        player->GetAnimator()->PlayAnimation(L"RightWalk");
    else if (Input::GetKey(eKeyCode::Left))
        player->GetAnimator()->PlayAnimation(L"LeftWalk");
    else if (Input::GetKey(eKeyCode::Up))
        player->GetAnimator()->PlayAnimation(L"UpWalk");
    else if (Input::GetKey(eKeyCode::Down))
        player->GetAnimator()->PlayAnimation(L"DownWalk");
}

void PlayerWalkState::Update(PlayerScript* player)
{
    Transform* tr = player->GetOwner()->GetComponent<Transform>();
    Vector2 pos = tr->GetPosition();
    Vector2 direction = Vector2::Zero;

    if (Input::GetKey(eKeyCode::Right))
        direction.x += 1.0f;
    if (Input::GetKey(eKeyCode::Left))
        direction.x -= 1.0f;
    if (Input::GetKey(eKeyCode::Up))
        direction.y -= 1.0f;
    if (Input::GetKey(eKeyCode::Down))
        direction.y += 1.0f;

    direction = direction.Normalized();
    pos += direction * player->GetMovement()->GetSpeed() * Time::DeltaTime();
    tr->SetPosition(pos);
}

void PlayerWalkState::Exit(PlayerScript* player)
{
}

PlayerScript::State PlayerWalkState::GetNextState(PlayerScript* player)
{
    if (!Input::GetKey(eKeyCode::Right) && !Input::GetKey(eKeyCode::Left) &&
        !Input::GetKey(eKeyCode::Up) && !Input::GetKey(eKeyCode::Down))
    {
        return PlayerScript::State::SitDown;
    }
    return PlayerScript::State::Walk;
}