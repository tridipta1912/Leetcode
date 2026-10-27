class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans = grid;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ans[i][(j + k) % m] = grid[i][j];
            }
        }
        swap(grid, ans);
        int tot = (k / m);
        int rem = (k % m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(j < rem) 
                {
                    ans[(i + tot + 1) % n][j] = grid[i][j];
                }
                else        
                {
                    ans[(i + tot) % n][j] = grid[i][j];
                }
            }
        }

        return ans;
    }
};