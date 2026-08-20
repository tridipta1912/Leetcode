class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        using ll = int;
        auto find = [&](int x)
        {
            map<ll, ll> mst;
            ll ptr = 0, ans = 0;
            while(ptr < nums.size() && mst.size() < x)
            {
                mst[nums[ptr]]++;
                ptr++;
            }
            for(ll i = 0; i < nums.size(); i++)
            {
                if(mst.size() == x) ans += (nums.size() - ptr + 1);
                mst[nums[i]]--;
                if(mst[nums[i]] == 0)
                {
                    mst.erase(nums[i]);
                    while(ptr < nums.size() && mst.size() != x)   
                    {
                        mst[nums[ptr]]++;
                        ptr++;
                    }
                }
            }
            return ans;
        };

        return -find(k + 1) + find(k);
    }
};