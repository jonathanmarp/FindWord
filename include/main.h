#ifndef MAIN_FIND_WORD_H_
#define MAIN_FIND_WORD_H_

#include <iostream>
#include <vector>

namespace FindWord {
	typedef std::vector<std::vector<char>> VectorWord;

	struct PositionCharacter {
		size_t x;
		size_t y;
	};
	
	typedef std::vector<std::vector<PositionCharacter>> ResultPosition;
}

#endif // MAIN_FIND_WORD_H_