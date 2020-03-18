#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
using namespace std;

class TrappingRainWater {
public:
	// Implement your solution by completing the below function`
	//Not so intuitive to come up with	
	int trap(vector<int>& height) {
	    int n = height.size();
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxleft) maxleft=height[left];
                else res+=maxleft-height[left];
                left++;
            }
            else{
                if(height[right]>=maxright) maxright= height[right];
                else res+=maxright-height[right];
                right--;
            }
        }
        return res;
	}
};

int main() {
	FastIO();
	int n;
	cin >> n;
	vector<int> heights;
	ReadMatrix<int>().OneDMatrix(n, heights);
	int result = TrappingRainWater().trap(heights);
	cout << result;
	return 0;
}
