class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int M = *max_element(nums.begin(), nums.end());
        vector<int> is_present(M + 1);
        for(auto x : nums)  is_present[x] = true;
        int ans = 0;
        for(int i = 1; i <= M; i++)
        {
            int g = 0;
            for(int j = i; j <= M; j += i)  if(is_present[j])   g = __gcd(g, j);
            ans += (g == i);
        }
        return ans;
    }
};