class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using ll = long long;
        priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> free;
        priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> running;
        queue<ll> pending;
        ll n = servers.size();
        ll m = tasks.size();
        for(ll i = 0; i < n; i++) free.push({servers[i], i});
        vector<int> ans(m);
        priority_queue<ll, vector<ll>, greater<ll>> time;
        for(ll i = 0; i < m; i++)   time.push(i);
        ll cur = 0;
        while(!time.empty())
        {
            auto t = time.top();
            time.pop();
            while(!running.empty() && running.top()[0] == t)
            {
                auto [t, i] = running.top();
                running.pop();
                free.push({servers[i], i});
            }
            while(cur <= min(m - 1, t))
            {
                pending.push(cur);
                cur++;
            }
            while(!pending.empty() && !free.empty())
            {
                ll idx = pending.front(); pending.pop();
                auto [_, i] = free.top(); free.pop();
                ans[idx] = i;
                running.push({t + tasks[idx], i});
                time.push({t + tasks[idx]});
            }
        }

        return ans;
    }
};