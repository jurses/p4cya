#ifndef NFA_H
#define NFA_H

#include "alphabet.hpp"
#include "state.hpp"

#include <set>
#include <stack>
#include <fstream>
#include <iostream>
#include <string>

typedef std::set<int> finiteStateIDSet_t;	// conjunto de estados finitos	// conjunto de punteros a estados finitos
typedef std::set<CYA::State> finiteStateSet_t;

namespace CYA{
	class Nfa{
	protected:
		Alphabet Sigma_;	//alfabeto
		int totalStates_;
		finiteStateSet_t Q_;	// totales
		finiteStateIDSet_t mainQ_;	// estados importantes
		finiteStateIDSet_t deathQ_;	// estados de muerte
		int initState_;	// estado inicial
		void analyze(int&, int, bool&);
		finiteStateIDSet_t funcTrans(const char, int);
		finiteStateIDSet_t funcTrans(const char, finiteStateIDSet_t);
		void organizeState(void);
		State obtActualState(int);
		std::string str2analyze_;
		std::ostream& showTrace(std::ostream&);
		bool checkAcceptance(finiteStateIDSet_t);
	public:
		Nfa(std::ifstream&);
		std::istream& putString(std::istream&);
		bool analyze(void);
	};
}

#endif	//NFA_H