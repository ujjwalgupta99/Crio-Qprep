#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
using namespace std;

class ValidParenthesis {
public:
    // Implement your solution by completing the below function	
	//Standard question for Stack (Also in ACM summer Challenge)
    bool isValid(string s) {
	stack<char> st;
    
	//traverse whole string
	//push all opening braces
	for(char c : s){
        if(c == '('|| c == '{' || c == '['){
            st.push(c);
        }
		
		//check for closing braces
		else{
            if(st.empty()) return false;
            if(c == ')' && st.top() != '(') return false;
            if(c == '}' && st.top() != '{') return false;
            if(c == ']' && st.top() != '[') return false;
            st.pop();
        }
    }
	//It is valid only if stack is finally empty
    return st.empty();
	
    }
};

int main() {
	FastIO();
	string s;
	getline(cin, s);
	bool result = ValidParenthesis().isValid(s);
	cout << boolalpha << result;
	return 0;
}
