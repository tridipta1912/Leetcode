class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, true);
        for(auto nodes: edges)
        {
            visited[nodes[1]] = false;
        }
        int ans = -1;
        for(int i = 0; i < n; i++)
        {
            if(visited[i])
            {
                if(ans == -1)   ans = i;
                else            return -1;
            }
        }
        return ans;
    }
};