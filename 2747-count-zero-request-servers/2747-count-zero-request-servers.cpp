class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        using ll = int;
        sort(logs.begin(), logs.end(), [&](auto &a, auto &b)
        {
            return (a[1] < b[1]);
        });
        for(auto &x : logs)    x[0]--;
        vector<int> freq(n);
        int ans = 0, ptr = 0;
        deque<int> dq;
        
        vector<array<int, 2>> q;
        for(int i = 0; i < queries.size(); i++)   q.push_back({queries[i], i});
        sort(q.begin(), q.end());

        vector<int> arr(queries.size());
        int m = logs.size();
        for(auto &[val, idx] : q)
        {
            while(ptr != m && logs[ptr][1] <= val)
            {
                if(freq[logs[ptr][0]] == 0) ans++;
                freq[logs[ptr][0]]++;
                dq.push_back(ptr);
                ptr++;
            }
            while(!dq.empty() && logs[dq.front()][1] < val - x)  
            {
                freq[logs[dq.front()][0]]--;
                if(freq[logs[dq.front()][0]] == 0)    ans--;
                dq.pop_front();
            }
            arr[idx] = n - ans;
        }
        return arr;
    }
};