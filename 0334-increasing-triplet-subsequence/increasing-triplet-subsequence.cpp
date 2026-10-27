class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        vector<int> suff(n);
        for(int i = 0; i < n; i++)
        {
            pref[i] = nums[i];
            if(i > 0)   pref[i] = min(pref[i], pref[i - 1]);
        }
        for(int i = n - 1; i >= 0; i--)
        {
            suff[i] = nums[i];
            if(i + 1 < n)   suff[i] = max(suff[i], suff[i + 1]);
        }
        for(int i = 1; i + 1 < n; i++)
        {
            if(nums[i] > pref[i - 1] && nums[i] < suff[i + 1])
            {
                return true;
            }
        }
        return false;
    }
};