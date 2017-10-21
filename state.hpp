#ifndef STATE_H
#define STATE_H

#include <map>
#include <set>
#include <ostream>
#include <cassert>

class CYA::State;
typedef std::set<int> finiteStateIDSet_t;
typedef std::map<char, finiteStateIDSet_t> adjacency_t;

namespace CYA{
	class State{
	private:
		int id_;
		bool acceptance_;
		adjacency_t tupleAdj;
	public:
		State();
		void setID(int);
		int getID(void)const;
		bool operator<(const State&)const;
		void setAdj(char, int);
		void setAcceptance(bool);
		finiteStateIDSet_t getNextS(const char)const;
		bool isAccepted(void)const;
		int nTrans(const char)const;
		int obtState(const char, int)const;
		operator int();
	};
}

#endif  // STATE_H