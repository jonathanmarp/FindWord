#include "../include/main.h"
#include "../include/FindVerticalUp.h"

namespace FindWord {
	ResultPosition FindVerticalUp(
		const VectorWord& randomWord,
		const std::string& search) {
		ResultPosition results = {};
		size_t xMax = randomWord[0].size();
		size_t yMax = randomWord.size();
	
		auto advance = [&](const size_t& x, const size_t& y) -> void {
			size_t GetLength = 0;
			std::vector<PositionCharacter> position;
			
			for(size_t i = 0; i < search.length(); i++) {
				if(((int)y - (int)i - 1) < 0) break;
				if(search[search.length() - i - 1] == 
					randomWord[y - i - 1][x]) {
					position.push_back({
						.x = x + 1,
						.y = static_cast<size_t>((y - i - 1)) + 1
					});
					GetLength += 1;
				}
			}
	
			if(GetLength == search.length()) {
				results.push_back(position);
			}
		};
	
		for(size_t x = 0; x < xMax; x++) {
			for(size_t y = yMax; y > 0; y--) {
				advance(x, y);	
			}
		}

		return results;
	}
}