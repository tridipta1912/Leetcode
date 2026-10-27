class Solution {
public:
    vector<int> col;
    bool b = true;
    void dfs(int u, vector<vector<int>> &graph, int color)
    {
        col[u] = color;
        for(auto v : graph[u])
        {
            if(col[v] == -1)
            {
                dfs(v, graph, color ^ 1);
            }
            else if(col[v] == color)
            {
                b = false;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        col.assign(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++)
        {
            if(col[i] == -1)
            {
                dfs(i, graph, 0);
            }
        }
        return b;
    }
};