class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> maxx, minn;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] >= 0)   maxx.push_back(nums[i]);
            else                minn.push_back(nums[i]);
        }
        sort(maxx.begin(), maxx.end(), greater<int>());
        sort(minn.begin(), minn.end());
        
        int ans = -(1e9 + 5);
        if(maxx.size() >= 3)    ans = maxx[0] * maxx[1] * maxx[2];
        if(minn.size() >= 2 && !maxx.empty())   ans = max(ans, minn[0] * minn[1] * maxx[0]);
        if(minn.size() >= 3)    
        {
            reverse(minn.begin(), minn.end());
            ans = max(ans, minn[0] * minn[1] * minn[2]);
        }
        return ans;
    }
};