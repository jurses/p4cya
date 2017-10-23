#include <iostream>
#include <map>
#include <set>
#include <utility>

typedef std::set<int> setInt_t;

int main(){
	int n, x;
	setInt_t s1, s2;
	std::map<char, setInt_t> m1;
	s1.insert(82);
	s2.insert(83);
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> x;
		s1.insert(x);
		m1.insert ( std::pair<char, setInt_t>('a',s1) );
	}

	std::cout << m1['a'].size() << std::endl;
	
	return 0;
}