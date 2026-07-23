class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int ans = 0, n = nums.size();
        if(n == 1)  return 1;
        if(n == 2)  return 2;
        int x = log2(n);
        ans = (1 << (x + 1));
        return ans;
    }
};