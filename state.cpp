#include "state.hpp"
#include <iostream>

typedef std::set<int> finiteStateIDSet_t;
typedef std::map<char, finiteStateIDSet_t> adjacency_t;

namespace CYA{
	State::State():
	id_(-1),
	acceptance_(false)
	{}

	State& State::operator=(const State& q){
		id_ = q.id_;
		acceptance_ = q.acceptance_;
		tupleAdj = q.tupleAdj;
		return *this;
	}
	
	void State::setAdj(char t, int nQ){
		 for(adjacency_t::iterator it = tupleAdj.begin(); it != tupleAdj.end(); it++){
			 if(t == it->first){
				 it->second.insert(nQ);
				 return;
			 }
		 }
		 finiteStateIDSet_t aux;
		 pairCS_t pairAux;
		 aux.insert(nQ);
		 pairAux.first = t;
		 pairAux.second = aux;
		 tupleAdj.insert(pairAux);
	}

	State::State(const State& q){
		id_ = q.id_;
		acceptance_ = q.acceptance_;
		tupleAdj = q.tupleAdj;
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
		return tupleAdj.at(t).size();
	}

	void State::setAcceptance(bool acceptance){
		acceptance_ = acceptance;
	}
}
