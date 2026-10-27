class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int pt1 = 0, pt2 = 0;
        while(ans.size() != (m + n))
        {
            if((pt2 == n) || (pt1 < m && nums1[pt1] < nums2[pt2]))
            {
                ans.push_back(nums1[pt1]);
                pt1++;
            }
            else
            {
                ans.push_back(nums2[pt2]);
                pt2++;
            }
        }
        swap(ans, nums1);
    }
};
