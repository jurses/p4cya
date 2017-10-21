#include "nfa.hpp"

#include <iostream>
#include <fstream>

using namespace CYA;

int main(void){
	std::ifstream ifs ("ejempl1.nfa", std::ifstream::in);
	Nfa nfa1(ifs);
}