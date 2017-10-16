#include "state.hpp"

namespace CYA{
	State::State():
	id_(-1),
	acceptance_(false)
	{}
	
	void State::setAdj(char t, int q){
		adjacency_[t] = q;
	}

	int State::getNextS(const char t)const{
		return adjacency_.at(t);
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

	State::operator int(){
		return id_;
	}
}