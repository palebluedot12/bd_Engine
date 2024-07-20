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

    // 정규화된 벡터를 반환하는 함수 (원본은 변경하지 않음)
    Vector2 Normalized() const
    {
        Vector2 result = *this;
        result.Normalize();
        return result;
    }

    // Scalar 곱셈을 위한 연산자 오버로딩
    Vector2 operator*(float scalar) const
    {
        return Vector2(x * scalar, y * scalar);
    }

    float Length() const
    {
        return std::sqrt(x * x + y * y);
    }

    // Scalar 곱셈의 교환법칙을 위한 전역 함수
    friend Vector2 operator*(float scalar, const Vector2& vec);

    // 벡터끼리 곱해서 벡터 반환
    Vector2 operator*(const Vector2& other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

};

inline Vector2 operator*(float scalar, const Vector2& vec)
{
    return vec * scalar;
}
