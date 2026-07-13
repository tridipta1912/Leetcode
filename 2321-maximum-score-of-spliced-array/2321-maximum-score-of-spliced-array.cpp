class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        auto find = [&](vector<int> &n1, vector<int> &n2)
        {
            int ans = 0;
            for(auto x : n1)    ans += x;
            int maxx = 0, sum = 0;
            for(int i = 0; i < nums1.size(); i++)
            {
                sum += (n2[i] - n1[i]);
                maxx = max(maxx, sum);
                sum = max(sum, 0);
            }
            return (ans + maxx);
        };
        return max(find(nums1, nums2), find(nums2, nums1));
    }
};