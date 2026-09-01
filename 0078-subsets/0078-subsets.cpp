class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        using ll = int;
        vector<vector<ll>> ans;
        for(ll i = 0; i < (1 << nums.size()); i++)
        {
            vector<ll> k;
            for(ll j = 0; j < nums.size(); j++) if((i >> j) & 1)    k.push_back(nums[j]);
            ans.push_back(k);
        }
        return ans;
    }
};