class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size() + 1);
        vis[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int u = q.front();  q.pop();
            for(auto v : rooms[u])
            {
                if(!vis[v])
                {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }

        
        return (accumulate(vis.begin(), vis.end(), 0) == rooms.size());
    }
};