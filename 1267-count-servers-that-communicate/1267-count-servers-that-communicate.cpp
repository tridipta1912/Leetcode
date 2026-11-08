class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> freq_row(m), freq_col(n);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j])  freq_row[i]++, freq_col[j]++;
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j])  ans += ((freq_row[i] > 1) || (freq_col[j] > 1));
            }
        }
        return ans;
    }
};