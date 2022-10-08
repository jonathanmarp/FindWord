#include "../include/main.h"
#include "../include/FindHorizontalRight.h"

namespace FindWord {
	ResultPosition FindHorizontalRight(
		const VectorWord& randomWord,
		const std::string& search) {
		ResultPosition results = {};
		
		auto AdvanceSearch = [&](const int& x, const int& y) -> void {
			size_t LengthGet = 0;
			std::vector<PositionCharacter> position;
			
			// aX = advance X
			for(size_t aX = x; aX < randomWord[y].size(); aX++) {
				if(search[(aX - x)] == randomWord[y][aX]) {
					position.push_back({
						.x = aX + 1,
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
			for(size_t x = 0; x < randomWord[y].size(); x++) {
				AdvanceSearch(x, y);
			}
		}

		return results;
	}
}