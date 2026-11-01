class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int suff = 0, pref = 0;
        vector<int> ans;
        for(auto &x : nums) suff += x;
        for(int i = 0; i < nums.size(); i++)
        {
            int p = (i * nums[i] - pref);
            int s = suff - ((nums.size() - i) * nums[i]);
            ans.push_back(p + s);
            pref += nums[i];
            suff -= nums[i];
        }
        return ans;
    }
};