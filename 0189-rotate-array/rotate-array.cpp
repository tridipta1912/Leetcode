class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = (n - k) % n + n;
        vector<int> nums1(n);
        for(int i = 0; i < n; i++)
        {
            nums1[i] = nums[(i + k) % n];
        }
        swap(nums1, nums);
    }
};