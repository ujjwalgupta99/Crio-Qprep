#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class TwoSum {
public:
    // Implement your solution by completing the below function	
	//simple linear time soln O(N), revise C++ STL once
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
		map<int,int> m;
		//could have done simply by 'auto' but meh
		map<int,int>::iterator it;

		for(int i=0;i<(int)nums.size();i++){

			int req = target - nums[i];
			it = m.find(req);

			if(it != m.end()){
				v.push_back(it->second);
				v.push_back(i);
			}
			// Key      value 
			m[nums[i]] = i;
		}

        return v;
    }
};

int main() {
	FastIO();
	int n, target;
	cin >> n;
	vector<int> nums;
	ReadMatrix<int>().OneDMatrix(n, nums);
	cin >> target;
	vector<int> result = TwoSum().twoSum(nums, target);
	PrintMatrix<int>().OneDMatrix(result, " ");
	return 0;
}
