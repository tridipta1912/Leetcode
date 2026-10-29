class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        vector<int> coord(st.begin(), st.end());
        for(auto &x : nums) x = lower_bound(coord.begin(), coord.end(), x) - coord.begin() + 1;

        int M = coord.size();
        vector<int> freq(M + 1);
        
        auto update = [&](int x, int val)
        {
            for(int i = x; i <= M; i += (i & (-i)))
            {
                freq[i] += val;
            }
        };

        auto sum = [&](int x)
        {
            int val = 0;
            for(int i = x; i > 0; i -= (i & (-i)))
            {
                val += freq[i];
            }
            return val;
        };

        vector<int> ans;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            update(nums[i], 1);
            ans.push_back(sum(nums[i] - 1));
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};