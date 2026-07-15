class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxx1(n), maxx2(n);
        for(int i = 0; i < n; i++)  
        {
            maxx1[i] = height[i];
            if(i)   maxx1[i] = max(maxx1[i], maxx1[i - 1]);
        }
        for(int i = n - 1; i >= 0; i--)  
        {
            maxx2[i] = height[i];
            if(i + 1 < n)   maxx2[i] = max(maxx2[i], maxx2[i + 1]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)  ans += max(min(maxx1[i], maxx2[i]) - height[i], 0);
        return ans;
    }
};