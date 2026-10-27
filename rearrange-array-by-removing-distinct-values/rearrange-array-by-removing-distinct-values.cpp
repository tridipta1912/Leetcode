class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        using ll = int;
        vector<ll> ans;
        while(!nums.empty())
        {
            vector<ll> n_nums, to_add;
            unordered_map<ll, ll> mp;
            for(auto x : nums)
                {
                    if(!mp[x])
                    {
                        mp[x] = true;
                        to_add.push_back(x);
                    }
                    else
                    {
                        n_nums.push_back(x);
                    }
                }
            sort(to_add.begin(), to_add.end());
            for(auto x : to_add)
                {
                    ans.push_back(x);
                }
            swap(n_nums, nums);
        }
        return ans;
    }
};