#pragma once

#include <memory>
#include <stack>

#include "State.h"


namespace Bartux {

	typedef std::unique_ptr<State> StateRef;

	class StateMachine
	{
	public:
		StateMachine() { }
		~StateMachine() { }

		void AddState(StateRef newState, bool isReplacing = true);
		void RemoveState();
		// W��czaj na pocz�tku ka�dej p�tli w Game.cpp
		void ProcessStateChanges();

		StateRef &GetActiveState();

	private:
		std::stack<StateRef> _states;
		StateRef _newState;

		bool _isRemoving;
		bool _isAdding, _isReplacing;
	};
}
