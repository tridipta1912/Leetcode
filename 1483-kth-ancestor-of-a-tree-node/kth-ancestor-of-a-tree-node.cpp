class TreeAncestor {
public:
    vector<vector<int>> adj;
    vector<vector<int>> par;
    int l;
    TreeAncestor(int n, vector<int>& parent) 
    {
        adj.resize(n);
        for(int i = 1; i < n; i++)
        {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        l = ceil(log2(n));
        par.assign(n, vector<int>(l + 1, -1));
        dfs(0, -1);
    }

    void dfs(int u, int p)
    {
        par[u][0] = p;
        for(int i = 1; i <= l; i++)
        {
            if(par[u][i - 1] != -1) par[u][i] = par[par[u][i - 1]][i - 1];
        }
        for(auto v : adj[u])
        {
            if(v != p)    dfs(v, u);
        }
    }
    int getKthAncestor(int node, int k) {
        for(int i = l; i >= 0; i--)
        {
            if(node == -1)  return -1;
            if((k - (1 << i)) >= 0)
            {
                k -= (1 << i);
                node = par[node][i];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */