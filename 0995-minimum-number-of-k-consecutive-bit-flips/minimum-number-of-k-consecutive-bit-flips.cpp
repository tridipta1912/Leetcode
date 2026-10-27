class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        using ll = int;
        ll ans = 0;
        ll cur = 0;
        deque<ll> dq;
        for(ll i = 0; i < nums.size(); i++)
        {
            while(!dq.empty() && dq.front() < i)
            {
                dq.pop_front();
            }
            cur = dq.size();
            nums[i] ^= (cur & 1);
            if(nums[i] == 0)
            {
                ans++;
                ll to_push = i + k - 1;
                if(to_push >= nums.size())  
                {
                    return -1;
                }
                dq.push_back(to_push);
            }
        }
        return ans;
    }
};