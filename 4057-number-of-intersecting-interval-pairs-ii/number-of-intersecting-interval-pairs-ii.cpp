class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        using ll = long long;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll ans = 0;
        for(auto x : intervals)
        {
            ll l = x[0], r = x[1];
            while(!pq.empty() && pq.top() < l)  pq.pop();
            ans += pq.size();
            pq.push(r);
        }
        return ans;
    }
};