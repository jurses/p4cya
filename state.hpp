#ifndef STATE_H
#define STATE_H

#include <map>
#include <set>
#include <ostream>
#include <cassert>
#include <utility>


typedef std::set<int> finiteStateIDSet_t;
typedef std::pair<char, finiteStateIDSet_t> pairCS_t;
typedef std::set<pairCS_t> adjacency_t;

namespace CYA{
	class State{
	private:
		int id_;
		bool acceptance_;
		adjacency_t tupleAdj;
	public:
		State();
		State(const State&);
		void setID(int);
		int getID(void)const;
		bool operator<(const State&)const;
		void setAdj(char, int);
		void setAcceptance(bool);
		finiteStateIDSet_t getNextS(const char)const;
		bool isAccepted(void)const;
		int nTrans(const char)const;
		int obtState(const char, int)const;
		void resize(int);
		State& operator=(const State&);
	};
}

#endif  // STATE_H