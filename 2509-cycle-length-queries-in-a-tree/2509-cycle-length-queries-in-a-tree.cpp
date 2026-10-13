class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> answer;
        for(auto x : queries)
        {
            int u = x[0], v = x[1];
            unordered_map<int, int> dist;
            dist[u] = 0;
            while(u)
            {
                dist[u / 2] = dist[u] + 1;
                u /= 2;
            }
            int cur = 0;
            while(v)    
            {
                if(dist.count(v))
                {
                    cur += dist[v];
                    break;
                }
                v /= 2;
                cur++;
            }
            answer.push_back(cur + 1);
        }
        return answer;
    }
};