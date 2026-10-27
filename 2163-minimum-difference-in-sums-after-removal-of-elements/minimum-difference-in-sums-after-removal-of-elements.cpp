class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        using ll = long long;
        ll n = nums.size();
        n /= 3;
        vector<ll> pref(3 * n, (ll)(1e15)), suff(3 * n, -(ll)(1e15));
        priority_queue<int> pq;
        ll sum = 0;
        for(int i = 0; i < n; i++)  pq.push(nums[i]), sum += nums[i];
        pref[n - 1] = sum;
        for(int i = n; i < 3 * n; i++)  
        {
            if(pq.top() > nums[i])
            {
                sum -= pq.top();
                pq.pop();
                pq.push(nums[i]);
                sum += nums[i];
            }
            pref[i] = sum;
        }

        priority_queue<int, vector<int>, greater<int>> qp;
        sum = 0;
        for(int i = 3 * n - 1; i > 2 * n - 1; i--)  qp.push(nums[i]), sum += nums[i];
        suff[(2 * n)] = sum;
        for(int i = 2 * n - 1; i >= 0; i--)  
        {
            if(qp.top() < nums[i])
            {
                sum -= qp.top();
                qp.pop();
                qp.push(nums[i]);
                sum += nums[i];
            }
            suff[i] = sum;
        }

        ll ans = (ll)(1e18);
        for(int i = 0; i + 1 < 3 * n; i++)
        {
            ans = min(ans, -suff[i + 1] + pref[i]);
        }
        return ans;
    }
};