class Solution {
public:
    void sortColors(vector<int>& nums) {
        using ll = long long;
        vector<ll> col(3);
        for(auto x : nums)  col[x]++;
        ll ptr = 0;
        for(ll i = 0; i < nums.size(); i++)
        {
            while(col[ptr] == 0)    ptr++;
            nums[i] = ptr;  col[ptr]--;
        }
    }
};