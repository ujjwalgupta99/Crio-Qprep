#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class MergeIntervals {
public:
	// Implement your solution by completing the below function
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
	//Sort to make traversing easier
	sort(intervals.begin(),intervals.end());
    
	    vector<vector<int>> result;
    
		//this is how you traverse a matrix 
	    for(unsigned int i=1;i<=intervals.size();i++){
            vector<int> insidearray;
    
			//Overlap Found like : (1,3) (2,5)
	        if(i<intervals.size() && intervals[i-1][1] >= intervals[i][0]){
               
			    intervals[i][0] = min(intervals[i-1][0],intervals[i][0]);
                intervals[i][1] = max(intervals[i-1][1], intervals[i][1]);
            }
    
			//No overlap found simply push the array to the matrix
	        else{
                insidearray.push_back(intervals[i-1][0]);
                insidearray.push_back(intervals[i-1][1]);
                result.push_back(insidearray);
            }
        }
       
	    return result;
    }
};

int main() {
    FastIO();
	int n;
	cin >> n;
	vector<vector<int>> nums;
	ReadMatrix<int>().TwoDMatrix(n, 2, nums);
	vector<vector<int>> result = MergeIntervals().merge(nums);
	PrintMatrix<int>().TwoDMatrix(result);
	return 0;
}
