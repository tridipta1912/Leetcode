class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        set<vector<int>> v;
        for(int i = 0;i<nums.size()-2;i++)
        {
            int target = -nums[i];
            int L = i + 1;
            int R = nums.size() - 1;
            while(L<R)
            {
                if(nums[L]+nums[R]<target)  L++;
                else if(nums[L]+nums[R]>target) R--;
                else if(nums[L]+nums[R]==target)    v.insert({nums[i],nums[L],nums[R]}), L++;
            }
        }
        vector<vector<int>> x;
        for(auto &h:v)  x.push_back(h);
        return x;
    }
};