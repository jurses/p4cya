#include "state.hpp"

//class CYA::State;
typedef std::set<int> finiteStateIDSet_t;
typedef std::map<char, finiteStateIDSet_t> adjacency_t;

namespace CYA{
	State::State():
	id_(-1),
	acceptance_(false)
	{}
	
	void State::setAdj(char t, int nQ){
		tupleAdj[t].insert(nQ);
	}

	int State::getID(void)const{
		return id_;
	}

	bool State::operator<(const State& q)const{
		return id_ < q.id_;
	}

	void State::setID(int id){
		id_ = id;
	}

	bool State::isAccepted(void)const{
		return acceptance_;
	}

	finiteStateIDSet_t State::getNextS(const char t)const{
		return tupleAdj.at(t);
	}

	int State::nTrans(const char t)const{
		return tupleAdj[t].size();
	}
}