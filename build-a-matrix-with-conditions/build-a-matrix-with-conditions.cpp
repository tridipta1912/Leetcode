class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        auto topo_sort = [&](vector<vector<int>> &arr)
        {
            vector<vector<int>> adj(k);
            vector<int> in(k);
            for(auto x : arr)
            {
                int u = x[0] - 1, v = x[1] - 1;
                adj[u].push_back(v);
                in[v]++;
            }
            vector<int> topo;
            queue<int> q;
            for(int i = 0; i < k; i++)
            {
                if(in[i] == 0)  q.push(i);
            }
            while(!q.empty())
            {
                auto u = q.front();
                q.pop();
                topo.push_back(u);
                for(auto v : adj[u])
                {
                    --in[v];
                    if(in[v] == 0)  q.push(v);
                }
            }
            return topo;
        };

        vector<int> row_topo = topo_sort(rowConditions);
        vector<int> col_topo = topo_sort(colConditions);

        if(row_topo.size() != k || col_topo.size() != k)
        {
            vector<vector<int>> empty;
            return empty;
        }
        vector<vector<int>> ans(k, vector<int>(k));
        vector<array<int, 2>> coordinates(k + 1);

        for(int i = 0; i < k; i++)
        {
            coordinates[row_topo[i] + 1][0] = i;
            coordinates[col_topo[i] + 1][1] = i;
        }

        for(int i = 1; i <= k; i++)
        {
            auto [x, y] = coordinates[i];
            ans[x][y] = i;
        }

        return ans;
    }
};