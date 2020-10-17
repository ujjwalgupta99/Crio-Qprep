//https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int countFreshOranges=0;
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    countFreshOranges++;
                else if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        
    vector<pair<int,int>> dirs={{-1,0},{0,-1},{1,0},{0,1}};
        int time=0;
        
      while (countFreshOranges != 0 && !q.empty())
		{
			size_t qsize = q.size();

			for (size_t i = 0; i < qsize; ++i)
			{
				auto [rottenI, rottenJ] = q.front();
				q.pop();

				for (const auto& d : dirs)
				{
					int newX = rottenI + d.first;
					int newY = rottenJ + d.second;
					if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1)
					{
                        grid[newX][newY] = 2;
						--countFreshOranges;
						q.push({ newX, newY });
					}
				}
			}

			++time;
		}
		return countFreshOranges == 0 ? time : -1;
        
    }
};