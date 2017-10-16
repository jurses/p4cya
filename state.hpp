#ifndef STATE_H
#define STATE_H

#include <map>
#include <ostream>

namespace CYA{
	class State{
	private:
		int id_;
		bool acceptance_;
		std::map<char, int> adjacency_;
		
	public:
		State();
		void setID(int);
		int getID(void)const;
		bool operator<(const State&)const;
		void setAdj(char, int);
		void setAcceptance(bool);
		int getNextS(const char)const;
		operator int();
	};
}

#endif  // STATE_H