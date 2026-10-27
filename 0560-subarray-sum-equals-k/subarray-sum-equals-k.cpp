class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int sum = 0;
        int count = 0;
        //Edge case
        if(nums.size()==1)
        {
            if(nums[0]==k)  return 1;
            else    return 0;
        }

        for(auto a:nums)
        {
            sum+=a;
            if(sum==k)  count++;
            count+=m[sum-k];
            m[sum]++;
        }
        return count;
    }
};