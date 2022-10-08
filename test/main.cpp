#include <iostream>

#include "../include/FindVerticalUp.h"

int main() {
	FindWord::VectorWord randomWord = {
		{ 'o', 'r', 'o', 'r' },
		{ 'r', 'o', 'r', 'o' },
		{ 'o', 'r', 'o', 'r' },
		{ 'r', 'o', 'r', 'o' }
	};
	std::string search = "oro";

	const FindWord::ResultPosition& result = FindWord::FindVerticalUp(
		randomWord,
		search
	);

	for(auto& y : result) {
		for(auto& x : y) {
			std::cout << "[" << x.x << " " << x.y << "]" << std::endl; 
		}
		std::cout << std::endl;
	}
	
	return 0;
}