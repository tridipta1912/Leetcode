class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int ans1 = 0;
        for(auto nums: arr1)    ans1 ^= nums;

        int ans2 = 0;
        for(auto nums: arr2)    ans2 ^= nums;

        return (ans1 & ans2);
    }
};