#pragma once
#include "CommonInclude.h"

enum class eKeyState
{
	Down,
	Pressed,
	Up,
	None,
};

enum class eKeyCode
{
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M,
	Left, Right, Down, Up, Enter, Back,
	End,
};

class Input
{
public:
	struct Key
	{
		eKeyCode keyCode;		// ��ư
		eKeyState state;		// ����
		bool bPressed;
	};

	static void Initailize();
	static void Update();

	static bool GetKeyDown(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Down; }
	static bool GetKeyUp(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Up; }
	static bool GetKey(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Pressed; }

private:
	static void CreateKeys();
	static void UpdateKeys();
	static void UpdateKey(Input::Key& key);
	static bool IsKeyDown(eKeyCode code);
	static void UpdateKeyDown(Input::Key& key);
	static void UpdateKeyUp(Input::Key& key);

private:
	//eKeyState mState[] = eKeyState::Up;
	static std::vector<Key> Keys;
};
