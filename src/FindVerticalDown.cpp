#include "../include/main.h"
#include "../include/FindVerticalDown.h"

namespace FindWord {
	ResultPosition FindVerticalDown(
		const VectorWord& randomWord,
		const std::string& search) {
		ResultPosition results = {};
		size_t xMax = randomWord[0].size();
		size_t yMax = randomWord.size();
	
		auto advance = [&](const size_t& x, const size_t& y) -> void {
			size_t GetLength = 0;
			std::vector<PositionCharacter> position;
			
			for(size_t i = 0; i < search.length(); i++) {
				if((y + i + 1) > (yMax)) break;
				
				if(search[i] == 
					randomWord[y + i][x]) {
					position.push_back({
						.x = x + 1,
						.y = static_cast<size_t>((y + i)) + 1
					});
					GetLength += 1;
				}
			}
	
			if(GetLength == search.length()) {
				results.push_back(position);
			}
		};
	
		for(size_t x = 0; x < xMax; x++) {
			for(size_t y = 0; y < yMax; y++) {
				advance(x, y);	
			}
		}

		return results;
	}
}