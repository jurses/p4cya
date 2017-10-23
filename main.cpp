#include "nfa.hpp"

#include <iostream>
#include <fstream>

using namespace CYA;

int main(void){
	std::ifstream ifs ("ejemplo1.nfa", std::ifstream::in);
	std::cout << "Hola" << std::endl;
	Nfa nfa1(ifs);
	
	nfa1.putString(std::cin);
	std::cout << nfa1.analyze() << std::endl;
}