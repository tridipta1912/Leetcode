class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n, 0);

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 1] + 1)  pre[i] = 1;
            pre[i] += pre[i - 1];
        }

        vector<int> ans;
        for(int i = 0; i < (n - k + 1); i++)
        {
            if(k == 1)  
            {
                ans.push_back(nums[i]);
                continue;
            }
            if(pre[i + k - 1] - pre[i] == (k - 1))  ans.push_back(nums[i + k - 1]);    
            else    ans.push_back(-1);
        }

        return ans;
    }
};