#pragma once
#include "ChickenState.h"

class ChickenScript;

class ChickenSitDownState : public ChickenState
{
public:
    void Enter(ChickenScript* chicken) override;
    void Update(ChickenScript* chicken) override;
    void Exit(ChickenScript* chicken) override;
};