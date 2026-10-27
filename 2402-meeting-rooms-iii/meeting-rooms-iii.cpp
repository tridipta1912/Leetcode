class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        priority_queue<long long, vector<long long>, greater<long long>> ava;
        for(long long i = 0; i < n; i++)
        {
            ava.push(i);
        }
        vector<long long> used(n);
        for(long long i = 0; i < meetings.size(); i++)
        {
            while(!pq.empty() && pq.top().first <= meetings[i][0])
            {
                ava.push(pq.top().second);
                pq.pop();
            }
            if(!ava.empty())
            {
                used[ava.top()]++;
                pq.push({meetings[i][1], ava.top()});
                ava.pop();
            }
            else
            {
                auto [end, room] = pq.top();
                pq.pop();
                used[room]++;
                pq.push({meetings[i][1] + (end - meetings[i][0]), room});
            }
        }
        long long ans = 0, room = 0;
        for(int i = 0; i < n; i++)  if(used[i] > ans)   ans = used[i], room = i;
        return (int)room;
    }
};