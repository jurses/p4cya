#ifndef NFA_H
#define NFA_H

#include "alphabet.hpp"
#include "state.hpp"

#include <set>
#include <fstream>

typedef std::set<CYA::State> finiteStateSet_t;	// conjunto de estados finitos

namespace CYA{
	class Nfa{
	protected:
		Alphabet Sigma_;	//alfabeto
		int totalStates_;
		finiteStateSet_t Q_;	// totales
		State initState;	// estado inicial
		finiteStateSet_t F_;	// de aceptación
	public:
		Nfa(std::ifstream&);
	};
}

#endif	//NFA_H