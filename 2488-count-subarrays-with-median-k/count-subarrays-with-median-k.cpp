class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int idx = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == k)    idx = i;
        }
        unordered_map<int, int> pref;   pref[0]++;
        int sum = 0, ans = 0;
        for(int i = idx - 1; i >= 0; i--)
        {
            if(nums[i] > k) sum++;
            else            sum--;
            pref[sum]++;
        }
        sum = 0;
        for(int i = idx; i < nums.size(); i++)
        {
            if(nums[i] > k) sum++;
            else if(nums[i] < k)    sum--;
            ans += pref[-sum];
            ans += pref[1 - sum];
        }
        return ans;
    }
};