class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<int> present1(10), present2(10);
        for(auto x : nums1) present1[x] = 1;
        for(auto y : nums2) present2[y] = 1;
        int ans = 99;
        for(int i = 1; i < 10; i++)
        {
            if(present1[i] && present2[i])  return i;
            for(int j = 1; j < 10; j++)
            {
                if(present1[i] && present2[j])  ans = min(ans, 10 * i + j), ans = min(ans, 10 * j + i);
                
            }
        }
        return ans;
    }
};