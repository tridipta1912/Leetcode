using ll = long long;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        ll ans = 0, sum = 0, cur = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)    cur += (i * nums[i]), sum += nums[i];
        ans = cur;
        for(int i = n - 1; i >= 0; i--)
        {
            cur += (sum - n * nums[i]);
            ans = max(ans, cur);
        }

        return (int)ans;
    }
};