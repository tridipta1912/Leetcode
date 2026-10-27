class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        long long f = target;
        vector<vector<int>> ans;
        set<vector<int>> v;
        if(nums.size()<=3)    return ans;
        sort(nums.begin(), nums.end());
        for (long long i = 0; i < static_cast<long long>(nums.size()) - 3; i++) {
            for (long long j = i + 1; j < static_cast<long long>(nums.size()) - 2; j++) {
                long long k = f - (nums[i] + nums[j]);
                long long R = (nums.size()) - 1;
                long long L = j + 1;
                while (L < R) {
                    if (nums[L] + nums[R] < k)
                        L++;
                    else if (nums[L] + nums[R] > k)
                        R--;
                    else if (nums[L] + nums[R] == k)
                        v.insert({nums[i], nums[j], nums[L++], nums[R--]});
                }
            }
        }
        
        for(auto &h:v)  ans.push_back(h);
        return ans;
    }
};
