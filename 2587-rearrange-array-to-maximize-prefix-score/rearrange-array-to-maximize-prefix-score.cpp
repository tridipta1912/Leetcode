class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long cnt = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            cnt += (sum > 0);
        }
        return cnt;
    }
};