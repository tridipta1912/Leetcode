class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        using ll = long long;
        int ans = 0;
        deque<int> maxx, seg;
        ll sum = 0;

        for(ll i = 0; i < chargeTimes.size(); i++)
        {
            sum += runningCosts[i];
            seg.push_back(i);
            while(!maxx.empty() && chargeTimes[i] > chargeTimes[maxx.back()])  maxx.pop_back();
            maxx.push_back(i);

            ll cost = chargeTimes[maxx.front()] + seg.size() * sum;
            while(cost > budget && !seg.empty())
            {
                ll u = seg.front(); seg.pop_front();
                sum -= runningCosts[u];
                if(maxx.front() == u)
                {
                    maxx.pop_front();
                }
                if(!maxx.empty())   cost = chargeTimes[maxx.front()] + seg.size() * sum;
            }
            if(!seg.empty() && cost <= budget)  ans = max(ans, static_cast<int>(seg.size()));
        }
        return ans;
    }
};