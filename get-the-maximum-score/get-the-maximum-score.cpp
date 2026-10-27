class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        using ll = long long;
        constexpr ll MOD = 1e9 + 7;
        ll n = nums1.size();
        ll m = nums2.size();
        ll ptr1 = 0, ptr2 = 0;
        ll dp1 = 0, dp2 = 0;
        while(ptr1 < n || ptr2 < m)
        {
            if (ptr1 < n && (ptr2 == m || nums1[ptr1] < nums2[ptr2])) 
            {
                dp1 += nums1[ptr1++];
            } 
            else if (ptr2 < m && (ptr1 == n || nums2[ptr2] < nums1[ptr1])) 
            {
                dp2 += nums2[ptr2++];
            } 
            else 
            {
                dp1 = dp2 = max(dp1, dp2) + nums1[ptr1];
                ptr1++;
                ptr2++;
            }
        }

        ll ways = max(dp1, dp2) % MOD;
        return ways;
    }
};