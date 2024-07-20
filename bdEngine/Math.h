#pragma once
#include <cmath>

struct Vector2
{
	static Vector2 One;
	static Vector2 Zero;

	float x;
	float y;

	Vector2()
		: x(0.0f)
		, y(0.0f)
	{

	}

	Vector2(float _x, float _y)
		: x(_x)
		, y(_y)
	{

	}

    Vector2 operator+(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator-(const Vector2& other) const
    {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 operator/(float value) const
    {
        return Vector2(x / value, y / value);
    }

    bool operator!=(const Vector2& other) const
    {
        return (x != other.x) || (y != other.y);
    }

    Vector2& operator+=(const Vector2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2& operator-=(const Vector2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    void Normalize()
    {
        float length = std::sqrt(x * x + y * y);
        if (length != 0)
        {
            x /= length;
            y /= length;
        }
    }

    // ����ȭ�� ���͸� ��ȯ�ϴ� �Լ� (������ �������� ����)
    Vector2 Normalized() const
    {
        Vector2 result = *this;
        result.Normalize();
        return result;
    }

    // Scalar ������ ���� ������ �����ε�
    Vector2 operator*(float scalar) const
    {
        return Vector2(x * scalar, y * scalar);
    }

    float Length() const
    {
        return std::sqrt(x * x + y * y);
    }

    // Scalar ������ ��ȯ��Ģ�� ���� ���� �Լ�
    friend Vector2 operator*(float scalar, const Vector2& vec);

    // ���ͳ��� ���ؼ� ���� ��ȯ
    Vector2 operator*(const Vector2& other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

};

inline Vector2 operator*(float scalar, const Vector2& vec)
{
    return vec * scalar;
}
