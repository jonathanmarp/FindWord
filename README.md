# Library FindWord

This library to search for words in, a collection of characters.

## Build
- Requirement
  - CMake >= 3.7
  - C++ Compiler (support C++ 17)

And below is the command:
```bash
$ cmake ..
$ make
```

## Example
```cpp
#include <iostream>

#include "FindVerticalUp.h"

// Or
// #include "FindVerticalDown.h"
// #include "FindHorizontalRight.h"
// #include "FindHorizontalLeft.h"

int main() {
	FindWord::VectorWord randomWord = {
		{ 'o', 'r', 'o', 'r' },
		{ 'r', 'o', 'r', 'o' },
		{ 'o', 'r', 'o', 'r' },
		{ 'r', 'o', 'r', 'o' }
	};
	std::string search = "oro";

  // Search from bottom to top
	const FindWord::ResultPosition& result = FindWord::FindVerticalUp(
		randomWord,
		search
	);
  
  // Or
  /*
    // Search from top to bottom
    const FindWord::ResultPosition& result = FindWord::FindVerticalDown(
      randomWord,
      search
    );
    
    // Search from left to right
    const FindWord::ResultPosition& result = FindWord::FindHorizontalRight(
      randomWord,
      search
    );
    
    // Search from right to left
    const FindWord::ResultPosition& result = FindWord::FindHorizontalLeft(
      randomWord,
      search
    );
  */

	for(auto& y : result) {
		for(auto& x : y) {
			std::cout << "[" << x.x << " " << x.y << "]" << std::endl; 
		}
		std::cout << std::endl;
	}
	
	return 0;
}
```
