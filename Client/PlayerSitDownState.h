#pragma once
#include "PlayerState.h"

class PlayerScript;

class PlayerSitDownState : public PlayerState
{
public:
    void Enter(PlayerScript* chicken) override;
    void Update(PlayerScript* chicken) override;
    void Exit(PlayerScript* chicken) override;
    PlayerScript::State GetNextState(PlayerScript* player) override;
};