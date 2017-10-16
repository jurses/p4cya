#include "nfa.hpp"

namespace CYA{
	Nfa::Nfa(std::ifstream& ifs){
		int totalStates, initStateID;
		ifs >> totalStates;
		ifs >> initStateID;
		initState.setID(initStateID);
		for(int i = 0; i < t)
	}
}