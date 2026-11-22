class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& par, string s) {
        int n = par.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++)  
        {
            int u = par[i], v = i;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<stack<int>> path(26);
        auto dfs = [&](this auto& self, int u, int p) -> void
        {
            if(!path[s[u] - 'a'].empty()) par[u] = path[s[u] - 'a'].top();
            path[s[u] - 'a'].push(u);
            for(auto v : adj[u])
            {
                if(v != p)
                {
                    self(v, u);
                }
            }
            path[s[u] - 'a'].pop();
        };
        dfs(0, -1);
        vector<int> sub(n, 1);
        adj.assign(n, vector<int>());
        for(int i = 1; i < n; i++)
        {
            int u = i;
            int v = par[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        auto dfs1 = [&](this auto& self, int u, int p) -> void
        {
            for(auto v : adj[u])
            {
                if(v != p)
                {
                    self(v, u);
                    sub[u] += sub[v];
                }
            }
        };
        dfs1(0, -1);
        return sub;
    }
};