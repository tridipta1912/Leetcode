class Solution {
public:
    int minDays(int n) {
        unordered_map<int, int> mp;
        queue<int> q;
        q.push(n);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if(u == 0)  break;
            if(u % 3 == 0)   
            {
                int v = u / 3;
                if(!mp.count(v))
                {
                    mp[v] = mp[u] + 1;
                    q.push(v);
                }
            }
            if (u % 2 == 0)    
            {
                int v = u / 2;
                if(!mp.count(v))
                {
                    mp[v] = mp[u] + 1;
                    q.push(v);
                }
            }
            int v = u - 1;
            if(!mp.count(v))
            {
                mp[v] = mp[u] + 1;
                q.push(v);
            }
        }

        return mp[0];
    }
};