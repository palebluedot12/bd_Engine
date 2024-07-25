#pragma once
#include "PlayerState.h"

class PlayerScript;

class PlayerWalkState : public PlayerState
{
public:
    void Enter(PlayerScript* player) override;
    void Update(PlayerScript* player) override;
    void Exit(PlayerScript* player) override;
    PlayerScript::State GetNextState(PlayerScript* player) override;
};