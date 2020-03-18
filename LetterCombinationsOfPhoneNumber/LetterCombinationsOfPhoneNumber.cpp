#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class LetterCombinationsOfPhoneNumber {
public:
    // Implement your solution by completing the below function
    vector<string> letterCombinations(string digits) {
    vector<string> results;
        
        if (digits.empty()) {
            return results;
        }

		// a look up table for corresponding characters on each keypad
        const char nums[8][4] = {
            {'a', 'b', 'c', ' '}, // 2
            {'d', 'e', 'f', ' '}, // 3
            {'g', 'h', 'i', ' '}, // 4
            {'j', 'k', 'l', ' '}, // 5
            {'m', 'n', 'o', ' '}, // 6
            {'p', 'q', 'r', 's'}, // 7
            {'t', 'u', 'v', ' '}, // 8
            {'w', 'x', 'y', 'z'}  // 9
        };
        
		// we'll need a queue to store the intermediate combinations
        queue<string> strCombinations;
		
		// push an empty string to start with
        strCombinations.push("");
        
        int currentKey = 0;
        const int MAX_KEY_PER_DIGIT = 4;
        
        while (!strCombinations.empty()) {
            
            int countCurrentCombination = strCombinations.size();
            
            while (countCurrentCombination--) {
                string firstStr = strCombinations.front();
                strCombinations.pop();

                // try to append all the keys presented by a single digit into the end of intermediate string
                for (int k = 0; k < MAX_KEY_PER_DIGIT; ++k) {
                    char charToInsert = nums[(digits[currentKey] - '2')][k];
                    
                    if (charToInsert == ' ') {
                        break;
                    }

                    string newStr(firstStr);
                    newStr.push_back(charToInsert);

                    if (newStr.length() == digits.length()) {
                        results.push_back(newStr);
                    } else {
                        strCombinations.push(newStr);
                    }
                }
            }

            ++currentKey;
        }
        
        return results;
    }
};

int main() {
	FastIO();
	string digits;
	cin >> digits;
	vector<string> combinations = LetterCombinationsOfPhoneNumber().letterCombinations(digits);
	PrintMatrix<string>().OneDMatrix(combinations, " ");
	return 0;
}