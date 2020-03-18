#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class NumberOfIslands {
public:
    // Implement your solution by completing the below function
    int numIslands(vector<string>& grid) {
        //int x = 0;
		if(grid.empty()){
            return 0;
        }
        int res = 0;
		//Row
        int m = grid.size();
        //Column
		int n = grid[0].size();
        //O(m*n) : Complexity
		for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]=='1'){
                    res++;
                    fill(grid,i,j);
                }
            }
        }
        return res;
        //return x;
    }

	void fill(vector<string>& grid, int i, int j){
        if(i >= 0 && i < (int)grid.size() && j >= 0 && j < (int)grid[0].size()){
            if(grid[i][j] == '1'){
                grid[i][j] = 'x';
				//fill the surrounding recursively with anything but 1 ('x' because it looks like minesweeper)
                fill(grid,i+1,j);
                fill(grid,i-1,j);
                fill(grid,i,j+1);
                fill(grid,i,j-1);
            }
        }
    }
};

int main() {
    FastIO();
	int n, m;
	cin >> n >> m;
	vector<string> grid;
	ReadMatrix<string>().OneDMatrix(n, grid);
	int result = NumberOfIslands().numIslands(grid);
	cout << result;
	return 0;
}
