class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
       
        int ans = 0;

        vector<int> vis(n);
        
        auto dfs = [&](this auto& self, int u) -> void
        {
            vis[u] = true;
            for(int v = 0; v < n; v++)
            {
                if(vis[v] || !isConnected[u][v])  continue;
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