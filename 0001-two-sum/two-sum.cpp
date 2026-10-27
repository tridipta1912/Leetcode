class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> mp;
    map<int,int> mp1;
    vector<int> ans;
    for(int i = 0;i<nums.size();i++)
    {
        if(mp[nums[i]]==0)
            mp[nums[i]]=(i+1);
        else
            mp1[nums[i]]=(i+1);
    }
    sort(nums.begin(),nums.end());
    int l = 0, r = nums.size()-1;
    while(l<r)
    {
        if(nums[l]+nums[r]==target)
        {
            break;
        }
        else if((nums[l]+nums[r])<target)  l++;
        else if((nums[l]+nums[r])>target)  r--;
    }
    if(nums[l]!=nums[r])
    {
        ans.push_back(mp[nums[l]]-1);
        ans.push_back(mp[nums[r]]-1);
    }
    else
    {
        ans.push_back(mp[nums[l]]-1);
        ans.push_back(mp1[nums[r]]-1);
    }
    return ans;
    }
};
