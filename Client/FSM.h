#pragma once
#include <unordered_map>
#include <functional>

template<typename T>
class FSM
{
public:
    // �� ������ �Լ�(����, ������Ʈ, ����)�� void(T*) ������ �Լ� ��ü
    using StateFunction = std::function<void(T*)>;

    void AddState(T state, StateFunction enterFunc, StateFunction updateFunc, StateFunction exitFunc)
    {
        m_States[state] = { enterFunc, updateFunc, exitFunc };
    }

    // ���� ���¸� ���ο� ���·� ����-> ���� ������ Exit�� �� ������ Enter �Լ� ȣ��
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