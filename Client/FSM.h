#pragma once
#include <unordered_map>
#include <functional>

template<typename T>
class FSM
{
public:
    // 각 상태의 함수(진입, 업데이트, 퇴출)은 void(T*) 형태의 함수 객체
    using StateFunction = std::function<void(T*)>;

    void AddState(T state, StateFunction enterFunc, StateFunction updateFunc, StateFunction exitFunc)
    {
        m_States[state] = { enterFunc, updateFunc, exitFunc };
    }

    // 현재 상태를 새로운 상태로 변경-> 이전 상태의 Exit과 새 상태의 Enter 함수 호출
    void SetState(T newState)
    {
        if (m_CurrentState != newState)
        {
            if (m_States.count(m_CurrentState) > 0)
                m_States[m_CurrentState].exitFunc(static_cast<T*>(this));

            m_CurrentState = newState;

            if (m_States.count(m_CurrentState) > 0)
                m_States[m_CurrentState].enterFunc(static_cast<T*>(this));
        }
    }

    void Update()
    {
        if (m_States.count(m_CurrentState) > 0)
            m_States[m_CurrentState].updateFunc(static_cast<T*>(this));
    }

    T GetCurrentState() const { return m_CurrentState; }

private:
    struct State
    {
        StateFunction enterFunc;
        StateFunction updateFunc;
        StateFunction exitFunc;
    };

    std::unordered_map<T, State> m_States;
    T m_CurrentState;
};