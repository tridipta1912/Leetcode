class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        using ll = long long;
        ll maxi = -1, mini = -1, st = 0;
        ll ans = 0;
        ll n = nums.size();
        for(ll i = 0; i < n; i++)
        {
            if(nums[i] > maxK || nums[i] < minK)
            {
                st = i + 1;
                maxi = -1;
                mini = -1;
                continue;
            }
            if(nums[i] == maxK) maxi = i;
            if(nums[i] == minK) mini = i;
            if(maxi != -1 && mini != -1)    ans += (min(maxi, mini) - st + 1);
        }
        return ans;
    }
};