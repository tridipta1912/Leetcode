class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 1)    ans.push_back(nums[i]);
        }
        int pro = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < ans.size(); i++)
        {
            int p = 1;
            for(int j = i; j < ans.size(); j++) 
            {
                p *= ans[j];
                pro = max(pro, p);
                if(p == 0)    break;
            }
        }

        return pro;
    }
};