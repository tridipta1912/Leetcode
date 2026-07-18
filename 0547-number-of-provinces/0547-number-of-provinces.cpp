class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> E(n, vector<int>());
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)  if(isConnected[i][j]) E[i].push_back(j);
        }

        int ans = 0;

        vector<int> vis(n);
        
        auto dfs = [&](this auto& self, int u) -> void
        {
            vis[u] = true;
            for(auto v : E[u])
            {
                if(vis[v])  continue;
                self(v);
            }
        };

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i);
            }
        }

        return ans;
    }
};