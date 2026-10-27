class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        for(auto nums:nums1)    if(m[nums]==0)  m[nums]++;
        for(auto nums:nums2)    if(m[nums]==1)  m[nums]++;
        vector<int> v;
        for(auto nums:m){
            if(nums.second>=2)  return(nums.first);
        }
        return -1;
    }
};