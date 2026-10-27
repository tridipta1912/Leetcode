class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26, 0);

        for(int i = 0; i < tasks.size(); i++)   v[tasks[i] - 'A']++;

        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        for(auto x : v)
        {
            if(x)   pq.push({0, -x});
        }
        int ans = 0;
        while(!pq.empty())
        {
            auto [a, b] = pq.top(); pq.pop();
            if(a < ans + 1) pq.push({ans + 1, b});
            else
            {
                ans = a;
                if(b < -1)  pq.push({ans + n + 1, b + 1});
            }
        }

        return ans;
    }
};