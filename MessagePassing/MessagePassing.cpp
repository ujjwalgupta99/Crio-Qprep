#include<bits/stdc++.h>
using namespace std;

//Biggest Module, try it once on your own
//To decompose the matrix into linear array(module 4), idk how to import functions like header files
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
            
            up++;
            if(up>down)break;
            
             //down
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

//Claasic DP question, refer "Jump Game" on Leetcode for logic
bool jumpLogic(vector<int> maze){
        int length = maze.size();
        int lastpos = length-1;
         for (int i= length-1; i >=0; i--){
            if((i + maze[i]) >= lastpos)
                lastpos = i;
         }
            
        return lastpos == 0;
}

// Implement your solution by completing the below function
bool canMessageBePassed(int n, vector<vector<int> > maze) {
        //bool possible = true;

        vector<int> flattenedArray = spiralOrder(maze);
       /* for (int i = 0; i < (int)flattenedArray.size(); i++)
        {
                cout<<flattenedArray[i]<<" ";
        }
        */
        bool possible = jumpLogic(flattenedArray);
	return possible;
}

int main() {
        int n , s , m;
        cin >> n >> s >> m;
        assert(1 <= n && n <= 500);
        assert(1 <= s && s <= 1e5);
        assert(1 <= m && m <= 1e5);

        vector<vector<int> > maze(n , vector<int>(n , 0));
        maze[0][0] = s;

        for(int i = 0 ; i < m ; ++i) {
            int x , y , p;
            cin >> x >> y >> p;
            assert(0 <= x && x < n);
            assert(0 <= y && y < n);
            assert(1 <= p && p <= 1e5);
            maze[x][y] = max(maze[x][y] , p);
        }
        bool possible = canMessageBePassed(n, maze);
        cout << (possible ? "Yes\n" : "No\n");
}


