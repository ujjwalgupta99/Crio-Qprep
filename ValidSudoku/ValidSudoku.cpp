#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        return isValidSudokuHelper(board);
    }
    bool ifValid(vector<vector<char>> &board, int r, int c, char ch)
    {
        // Check for the same row
        for (int i = 0; i < 9; i++)
        {
            if (board[r][i] == ch)
            {
                return false;
            }
        }

        // Check for the same coloumn
        for (int i = 0; i < 9; i++)
        {
            if (board[i][c] == ch)
            {
                return false;
            }
        }

        // Check in the same grid(3*3)
        int rr = r - (r % 3);
        int cc = c - (c % 3);
        for (int i = rr; i < (rr + 3); i++)
        {
            for (int j = cc; j < (cc + 3); j++)
            {
                if (board[i][j] == ch)
                {
                    return false;
                }
            }
        }
        return true;
    }

    // The recursive helper function
    bool isValidSudokuHelper(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {

                // If the cell is filled
                if (board[i][j] != '.')
                {

                    // Store the value in ch, and empty the cell
                    char ch = board[i][j];
                    board[i][j] = '.';

                    // Check if it is valid
                    if (!ifValid(board, i, j, ch))
                        return false;

                    // If valid, store the value back
                    board[i][j] = ch;
                }
            }
        }
        return true;
    }
};
int main()
{
    FastIO();
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    Solution().isValidSudoku(board) ? cout << "YES\n" : cout << "NO\n";

    return 0;
}