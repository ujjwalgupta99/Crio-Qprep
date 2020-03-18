#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
using namespace std;

class StringToIntegerAtoi {
public:
    // Implement your solution by completing the below function	
	//Simple If-Else practise question, No logic
    int myAtoi(string str) {
    	//int ans = 0;
	if (str.empty()) return 0;
    
	int i = 0, sign = 1;
    //isspace() : Library to check for spaces,returns true for space input
	while (i + 1 < (int)str.size() && isspace(str[i])) 
		i++;

	long res = 0;
    //sign determination
	if (str[i] == '-' || str[i] == '+')
	 	sign = (str[i++] == '-')? -1 : 1;


    while (i < (int)str.size()) {
        if (isdigit(str[i]))
			 res = 10 * res + (str[i++] - '0');
        else 
			return res * sign;
        //Edge-Case
		if (res > INT_MAX) 
			return sign == -1 ? INT_MIN : INT_MAX;
	}
         return res * sign;
    }
        //return ans;
};

int main() {
	FastIO();
	string str;
	cin >> str;
	int result = StringToIntegerAtoi().myAtoi(str);
	cout << result;
	return 0;
}
