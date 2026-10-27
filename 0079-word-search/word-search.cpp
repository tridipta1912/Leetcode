class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        int n = board.size();
        int m = board[0].size();

        function<bool(int, int, int, vector<vector<bool>>&)> dfs = [&](int x, int y, int idx, vector<vector<bool>> &vis) 
        {
            if(idx == word.size() - 1) return true;

            for(int i = 0; i < 4; i++) 
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && board[nx][ny] == word[idx + 1]) 
                {
                    vis[nx][ny] = true;
                    if(dfs(nx, ny, idx + 1, vis)) return true;
                    vis[nx][ny] = false;
                }
            }
            return false;
        };

        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                if(board[i][j] == word[0]) 
                {
                    vector<vector<bool>> vis(n, vector<bool>(m, false));
                    vis[i][j] = true;
                    if(dfs(i, j, 0, vis)) return true;
                }
            }
        }
        return false;
    }
};
