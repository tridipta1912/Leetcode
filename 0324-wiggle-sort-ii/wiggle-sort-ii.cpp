class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> nums1 = nums;
        sort(nums1.begin(), nums1.end());
        vector<int> nums2 = nums;
        int ptr = 0;
        for(int i = 0; i < nums.size(); i += 2) nums2[i] = nums1[ptr++];
        for(int i = 1; i < nums.size(); i += 2) nums2[i] = nums1[ptr++];

        int idx = 0;
        for(int i = 1; i < nums.size(); i++)    if(nums2[i] == nums2[i - 1])    idx = i;
        for(int i = 0; i < nums.size(); i++)    nums[i] = nums2[(i + idx) % nums.size()];
    }
};