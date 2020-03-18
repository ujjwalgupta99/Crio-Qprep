#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class MatrixTraversal {
public:
    // Implement your solution by completing the below function	
    vector<int> traversalPath(vector<vector<int>>& matrix, int currPosX, int currPosY, int dirToMove, int stepsToMove) {
        vector<int> res;

		while(stepsToMove--){
				switch ((dirToMove))
				{
					//right 
					case 1:
						currPosY++;
					break;
				
					//Down 
					case 2:
						currPosX++;
					break;

					//Left 
					case 3:
						currPosY--;
					break;

					//Up 
					case 4:
						currPosX--;
					break;
				}
			//												that's how you find matrix dimensions
			if(currPosX<0 || currPosY<0 || currPosX>=int(matrix.size()) || currPosY>=int(matrix[0].size())){
				//Need to clear vector otherwise previous results would reflect
				res.clear();
				res.push_back(-1);
				return res;
			}
			res.push_back(matrix[currPosX][currPosY]);
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

	int currPosX, currPosY, dirToMove, stepsToMove;
	cin >> currPosX >> currPosY;
	cin >> dirToMove >> stepsToMove;

	vector<int> result = MatrixTraversal().traversalPath(matrix, currPosX, currPosY, dirToMove, stepsToMove);
	PrintMatrix<int>().OneDMatrix(result, " ");
	return 0;
}
