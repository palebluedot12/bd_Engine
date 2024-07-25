// FSM.h
#pragma once
#include <unordered_map>
#include <memory>

template<typename T, typename StateType>
class FSM {
public:
    class State 
    {
    public:
        virtual ~State() = default;
        virtual void Enter(T* owner) = 0;
        virtual void Update(T* owner) = 0;
        virtual void Exit(T* owner) = 0;
    protected:
        void SetState(T* owner, StateType newState) {
            owner->GetFSM()->SetState(newState);
        }
    };

    void AddState(StateType stateType, std::unique_ptr<State> state) {
        m_States[stateType] = std::move(state);
    }

    void SetState(StateType newState) {
        if (m_CurrentState != newState) {
            if (m_States.count(m_CurrentState) > 0)
                m_States[m_CurrentState]->Exit(m_Owner);
            m_CurrentState = newState;
            if (m_States.count(m_CurrentState) > 0)
                m_States[m_CurrentState]->Enter(m_Owner);
        }
    }

    void Update() {
        if (m_States.count(m_CurrentState) > 0) {
            m_States[m_CurrentState]->Update(m_Owner);
        }
    }

    StateType GetCurrentState() const { return m_CurrentState; }
    void SetOwner(T* owner) { m_Owner = owner; }

private:
    std::unordered_map<StateType, std::unique_ptr<State>> m_States;
    StateType m_CurrentState;
    T* m_Owner;
};