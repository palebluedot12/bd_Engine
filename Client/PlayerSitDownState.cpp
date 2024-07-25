#include "PlayerSitDownState.h"
#include "PlayerScript.h"
#include "..\\bdEngine\\InputManager.h"

void PlayerSitDownState::Enter(PlayerScript* player)
{
    player->GetAnimator()->PlayAnimation(L"SitDown", false);
}

void PlayerSitDownState::Update(PlayerScript* player)
{
}

void PlayerSitDownState::Exit(PlayerScript* player)
{
}

PlayerScript::State PlayerSitDownState::GetNextState(PlayerScript* player)
{
    if (Input::GetKey(eKeyCode::Right) || Input::GetKey(eKeyCode::Left) ||
        Input::GetKey(eKeyCode::Up) || Input::GetKey(eKeyCode::Down))
    {
        return PlayerScript::State::Walk;
    }
    return PlayerScript::State::SitDown;
}