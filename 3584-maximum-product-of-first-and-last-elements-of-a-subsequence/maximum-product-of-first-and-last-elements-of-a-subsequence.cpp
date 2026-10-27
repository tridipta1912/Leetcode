class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) 
    {
        long long ans = -(long long)(1e18);
        vector<int> max_pref = nums, min_pref = nums, max_suff = nums, min_suff = nums;

        for(int i = 1; i < nums.size(); i++)
        {
            max_pref[i] = max(max_pref[i], max_pref[i - 1]);
            min_pref[i] = min(min_pref[i], min_pref[i - 1]);
        }

        for(int i = nums.size() - 2; i >= 0; i--)
        {
            max_suff[i] = max(max_suff[i], max_suff[i + 1]);
            min_suff[i] = min(min_suff[i], min_suff[i + 1]);
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(i + (m - 1) == nums.size())  break;
            ans = max(ans, (long long)max_pref[i] * max_suff[i + m - 1]);
            ans = max(ans, (long long)min_pref[i] * min_suff[i + m - 1]);
        }

        return ans;
    }
};