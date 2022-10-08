#include "../include/main.h"
#include "../include/FindHorizontalLeft.h"

namespace FindWord {
	ResultPosition FindHorizontalLeft(
		const VectorWord& randomWord,
		const std::string& search) {
		ResultPosition results = {};
		
		auto AdvanceSearch = [&](const int& x, const int& y) -> void {
			size_t LengthGet = 0;
			std::vector<PositionCharacter> position;
			
			// aX = advance X
			for(size_t aX = (x + 1); aX > 0; aX--) {
				if(search[((x + 1) - aX)] == randomWord[y][aX - 1]) {
					position.push_back({
						.x = (aX - 1) + 1, 
						// because aX is added by one 
						// then to equalize again subtract one
						.y = static_cast<size_t>(y) + 1
					});
					LengthGet += 1;
				}
			}
	
			if(LengthGet == search.length()) {
				results.push_back(position);
			}
		};
		
		for(size_t y = 0; y < randomWord.size(); y++) {
			for(size_t x = (randomWord[y].size() - 1); x > 0; x--) {
				AdvanceSearch(x, y);
			}
		}

		return results;
	}
}