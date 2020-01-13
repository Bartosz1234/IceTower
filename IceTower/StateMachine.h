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
		// W³¹czaj na pocz¹tku ka¿dej pêtli w Game.cpp
		void ProcessStateChanges();

		StateRef &GetActiveState();

	private:
		std::stack<StateRef> _states;
		StateRef _newState;

		bool _isRemoving;
		bool _isAdding, _isReplacing;
	};
}
