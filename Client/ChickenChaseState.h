#pragma once
#include "ChickenState.h"

class ChickenScript;

class ChickenChaseState : public ChickenState
{
public:
    void Enter(ChickenScript* chicken) override;
    void Update(ChickenScript* chicken) override;
    void Exit(ChickenScript* chicken) override;
};
