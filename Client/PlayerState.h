#pragma once
#include "PlayerScript.h"

class PlayerScript;

class PlayerState
{
public:
    virtual ~PlayerState() {}
    virtual void Enter(PlayerScript* chicken) = 0;
    virtual void Update(PlayerScript* chicken) = 0;
    virtual void Exit(PlayerScript* chicken) = 0;
    virtual PlayerScript::State GetNextState(PlayerScript* player) = 0;
};