class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        vector<int> v;
        for(auto nums:nums1)    if(m[nums]==0)  m[nums] = 1;
        for(auto nums:nums2)    if(m[nums]==1)  m[nums] = 2, v.push_back(nums);
        
        
        return v;
    }
};