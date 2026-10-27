class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        using ll = long long;
        int n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1);
        for(int i = 0; i < n; i++)
        {
            prefix[i] = nums[i];
            if(i > 0) prefix[i] *= prefix[i - 1];
        }
        for(int i = n - 1; i >= 0; i--)
        {
            suffix[i] = nums[i];
            if(i != n - 1)  suffix[i] *= suffix[i + 1];
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            int val = 1;
            if(i > 0)   val *= prefix[i - 1];
            if(i < n - 1)   val *= suffix[i + 1];
            ans.push_back(val);
        }
        return ans;
    }
};