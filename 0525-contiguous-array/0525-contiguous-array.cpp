class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = 0;
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += ((nums[i] == 1) ? 1 : -1);
            if(sum != 0 && mp[sum] == 0)    mp[sum] = i + 1;
            ans = max(ans, i - mp[sum] + 1);
        }
        return ans;
    }
};