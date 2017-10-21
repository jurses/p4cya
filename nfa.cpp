#include "nfa.hpp"

typedef std::set<int> finiteStateIDSet_t;
typedef std::map<char, finiteStateIDSet_t> adjacency_t;

namespace CYA{
	Nfa::Nfa(std::ifstream& ifs){
		int totalStates;
		ifs >> totalStates;
		ifs >> initState_;
		for(int i = 0; i < totalStates_; i++){
			bool acceptance;
			int state, nStates;
			ifs >> state;
			ifs >> acceptance;
			ifs >> nStates;
			State tempState;
			tempState.setID(state);
			tempState.setAcceptance(acceptance);
			for(int j = 0; j < nStates; j++){
				char trans;
				int nextState;
				ifs >> trans;
				ifs >> nextState;
				Sigma_.insert(trans);
				tempState.setAdj(trans, nextState);
			}
			Q_.insert(tempState);
		}
		organizeState();
	}

	void Nfa::organizeState(void){
		// conseguir los estados importantes y los de muerte
	}

	State* Nfa::obtActualState(int q){
		for(finiteStateSet_t::iterator it = Q_.begin; it != Q_.end(); it++)
			if(it->getID == q)
				return &*it;
	}

	finiteStateIDSet_t Nfa::funcTrans(const char t, int q){
		State *actualState = obtActualState(q);
		return actualState->getNextS(t);
	}

	finiteStateIDSet_t Nfa::funcTrans(const char t, finiteStateIDSet_t qStates){
		
	}

	std::istream& Nfa::putString(std::istream& is){
		is >> str2analyze_;
		return is;
	}

	std::ostream& Nfa::showTrace(std::ostream& os){
		os << 
		return os;
	}

	bool Nfa::checkAcceptance(finiteStateIDSet_t qStates){
		State *q;
		for(finiteStateIDSet_t::iterator it = qStates.begin(); it != qStates.end(); it++){
			q = obtActualState(*it);
			if(q->isAccepted())
				return true;
		}

		return false;
	}

	void Nfa::analyze(int& i, int qID, bool& accepted){
		State *q = obtActualState(qID);
		while(i < str2analyze_.size() && i >=0){
			for(int j = 0; j < q->nTrans(str2analyze_[i]); j++){
				finiteStateIDSet_t x = q->getNextS(str2analyze_[i]);
				if(x.empty()){
					i--;
					break;
				}
				
				i++;

				if(i == str2analyze_.size()){
					for(finiteStateIDSet_t::iterator it = x.begin(); it != x.end(); it++){
						State *qA = obtActualState(*it);
						if(qA->isAccepted())
							accepted = true;
							return;
					}
					accepted = false;
					return;
				}
				else
					for(finiteStateIDSet_t::iterator it = x.begin(); it != x.end(); it++)
						analyze(i, obtActualState(*it));
			}
		}
	}

	bool Nfa::analyze(void){
		int i = 0;
		State *q = obtActualState(initState_);
		bool accepted;
		while(i < str2analyze_.size() && i >=0){
			for(int j = 0; j < q->nTrans(str2analyze_[i]); j++){
				finiteStateIDSet_t x = q->getNextS(str2analyze_[i]);
				if(x.empty()){
					i--;
					break;
				}
				
				i++;

				if(i == str2analyze_.size()){
					for(finiteStateIDSet_t::iterator it = x.begin(); it != x.end(); it++){
						State *qA = obtActualState(*it);
						if(qA->isAccepted())
							return qA->isAccepted();
					}
					return false;
				}
				else
					for(finiteStateIDSet_t::iterator it = x.begin(); it != x.end(); it++)
						analyze(i, obtActualState(*it), accepted);
			}
		}
	}


}