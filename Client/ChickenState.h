#pragma once

class ChickenScript;

class ChickenState
{
public:
    virtual ~ChickenState() {}
    virtual void Enter(ChickenScript* chicken) = 0;
    virtual void Update(ChickenScript* chicken) = 0;
    virtual void Exit(ChickenScript* chicken) = 0;
};