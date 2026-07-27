class Solution {
public:
    int maximalSquare(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                matrix[i][j] += (grid[i][j] - '0');
                if(i && j)  matrix[i][j] -= matrix[i - 1][j - 1];
                if(i)   matrix[i][j] += matrix[i - 1][j];
                if(j)   matrix[i][j] += matrix[i][j - 1];
            }
        }

        auto find = [&](int r1, int c1, int r2, int c2)
        {
            int ans = matrix[r2][c2];
            if(r1 && c1)    ans += matrix[r1 - 1][c1 - 1];
            if(r1)  ans -= matrix[r1 - 1][c2];
            if(c1)  ans -= matrix[r2][c1 - 1];
            return ans; 
        };

        auto check = [&](int k)
        {
            for(int i = 0; i + k - 1 < n; i++)
            {
                for(int j = 0; j  + k - 1 < m; j++)
                {
                    int r1 = i, r2 = i + k - 1;
                    int c1 = j, c2 = j + k - 1;
                    if(find(r1, c1, r2, c2) == k * k)   return true;
                }
            }
            return false;
        };

        int L = 1, R = min(m, n);
        int ans = 0;
        while(L <= R)
        {
            int M = L + (R - L) / 2;
            if(check(M))
            {
                ans = M;
                L = M + 1;
            }
            else
            {
                R = M - 1;
            }
        }

        ans *= ans;
        return ans;
    }
};