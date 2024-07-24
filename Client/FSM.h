#pragma once
#include <unordered_map>
#include <functional>

template<typename T, typename StateType>
class FSM {
public:
    using StateFunction = void (T::*)();

    void AddState(StateType state, StateFunction enterFunc, StateFunction updateFunc, StateFunction exitFunc) {
        m_States[state] = { enterFunc, updateFunc, exitFunc };
    }

    void SetState(StateType newState) {
        if (m_CurrentState != newState) {
            if (m_States.count(m_CurrentState) > 0)
                (m_Owner->*m_States[m_CurrentState].exitFunc)();

            m_CurrentState = newState;

            if (m_States.count(m_CurrentState) > 0)
                (m_Owner->*m_States[m_CurrentState].enterFunc)();
        }
    }

    void Update() {
        if (m_States.count(m_CurrentState) > 0)
            (m_Owner->*m_States[m_CurrentState].updateFunc)();
    }

    StateType GetCurrentState() const { return m_CurrentState; }

    void SetOwner(T* owner) { m_Owner = owner; }

private:
    struct State {
        StateFunction enterFunc;
        StateFunction updateFunc;
        StateFunction exitFunc;
    };

    std::unordered_map<StateType, State> m_States;
    StateType m_CurrentState;
    T* m_Owner;
};