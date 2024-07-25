#pragma once
#include "FSM.h"
#include "ChickenScript.h"

class ChickenChaseState : public FSM<ChickenScript, ChickenScript::State>::State
{
public:
    void Enter(ChickenScript* chicken) override;
    void Update(ChickenScript* chicken) override;
    void Exit(ChickenScript* chicken) override;
};
