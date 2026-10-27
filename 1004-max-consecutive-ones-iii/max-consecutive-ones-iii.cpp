class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        using ll = long long;
        ll cur = 0, ans = 0;
        ll ptr = 0;
        for(ll i = 0; i < nums.size(); i++)
        {
            cur += (nums[i] == 0);
            if(cur > k)
            {
                while (cur != k)
                {
                    cur -= (nums[ptr] == 0);
                    ptr++;
                }
            }
            ans = max(ans, i - ptr + 1);
        }
        return ans;
    }
};