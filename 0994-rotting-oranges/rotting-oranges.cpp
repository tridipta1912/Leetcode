//You are given an m x n grid where each cell can have one of three values: 
//
// 
// 0 representing an empty cell, 
// 1 representing a fresh orange, or 
// 2 representing a rotten orange. 
// 
//
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten 
//orange becomes rotten. 
//
// Return the minimum number of minutes that must elapse until no cell has a 
//fresh orange. If this is impossible, return -1. 
//
// 
// Example 1: 
// 
// 
//Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
//Output: 4
// 
//
// Example 2: 
//
// 
//Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
//Output: -1
//Explanation: The orange in the bottom left corner (row 2, column 0) is never 
//rotten, because rotting only happens 4-directionally.
// 
//
// Example 3: 
//
// 
//Input: grid = [[0,2]]
//Output: 0
//Explanation: Since there are already no fresh oranges at minute 0, the answer 
//is just 0.
// 
//
// 
// Constraints: 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 10 
// grid[i][j] is 0, 1, or 2. 
// 
//
// Related Topics Array Breadth-First Search Matrix \U0001f44d 14112 \U0001f44e 445


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        using ll = long long;
        vector<ll> dx = {1, -1, 0, 0};
        vector<ll> dy = {0, 0, 1, -1};

        queue<pair<ll, ll>> q;
        ll n = grid.size();
        ll m = grid[0].size();
        vector<vector<ll>> ans(n, vector<ll>(m, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0 ; j < m; j++)
            {
                if (grid[i][j] == 2)    q.push({i, j}), ans[i][j] = 0;
            }
        }

        int val = 0;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                ll nx = x + dx[i];
                ll ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (ans[nx][ny] != -1 || grid[nx][ny] != 1) continue;
                ans[nx][ny] = ans[x][y] + 1;
                val = max(val, (int)ans[nx][ny]);
                q.push({nx, ny});
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(ans[i][j] == -1 && grid[i][j] == 1)  
                {
                    return -1;
                }
            }
        }
        return val;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
