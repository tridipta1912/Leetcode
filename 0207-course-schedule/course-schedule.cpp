class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> in(n);
        for(auto& edge : prerequisites)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); 
            in[v]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(in[i] == 0)  q.push(i);
        }

        int cnt = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            cnt++;
            for(auto v : adj[u])
            {
                if(--in[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        return (cnt == n);
    }
};