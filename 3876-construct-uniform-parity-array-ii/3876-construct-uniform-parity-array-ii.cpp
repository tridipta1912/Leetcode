class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());
        if(nums1[0] & 1) return true;
        for(auto x : nums1) if(x % 2 != nums1[0] % 2)   return false;
        return true;
    }
};