#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class SpiralMatrix {
public:
    // Implement your solution by completing the below function	
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
		int n = matrix.size(), m = matrix[0].size();
		if (matrix.empty()) 
            return res;
        
        int up=0, down=n-1, left=0, right=m-1;
        
        while(left<=right&&up<=down){
            
            //Right
            for(int i=left; i<=right; i++){
               res.push_back(matrix[up][i]);  
            }
            
            //down
            up++;
            if(up>down)break;
            
            for(int j=up; j<=down; j++){
                res.push_back(matrix[j][right]);
            }
            
            right--;
            if(left>right)break;
            
            //left
            for(int j=right; j>=left; j--){
                res.push_back(matrix[down][j]);
            }
            
            down--;
            if(up>down)break;
            
            //Up
            for(int i=down; i>=up; i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};

int main() {
    FastIO();
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix;
	ReadMatrix<int>().TwoDMatrix(n, m, matrix);
	vector<int> result = SpiralMatrix().spiralOrder(matrix);
	PrintMatrix<int>().OneDMatrix(result, " ");
	return 0;
}
