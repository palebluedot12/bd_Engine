#pragma once
#include "Component.h"
#include "CommonInclude.h"

class Movement : public Component
{
public:
    Movement();
    ~Movement() override;

    void Update() override;

    void SetDirection(const Vector2& direction) { m_Direction = direction; }
    void SetSpeed(float speed) { m_Speed = speed; }

private:
    Vector2 m_Direction;
    float m_Speed;
};

