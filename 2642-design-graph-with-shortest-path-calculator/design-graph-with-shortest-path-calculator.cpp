using ll = int;
class Graph {
private:
    vector<vector<int>> dp;
    int n;
public:
    Graph(int n1, vector<vector<int>>& edges) : n{n1} {
        dp.assign(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++)  dp[i][i] = 0;
        for(auto edge : edges)
        {
            ll u = edge[0], v = edge[1], w = edge[2];
            if(dp[u][v] > w)
            {
                dp[u][v] = w;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++) 
                    {
                        dp[i][j] = min(dp[i][j], dp[i][u] + w + dp[v][j]);
                    }
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        ll u = edge[0], v = edge[1], w = edge[2];
        if(dp[u][v] > w)
        {
            dp[u][v] = w;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++) 
                {
                    dp[i][j] = min(dp[i][j], dp[i][u] + w + dp[v][j]);
                }
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return ((dp[node1][node2] == 1e9) ? -1 : dp[node1][node2]);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */