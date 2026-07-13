class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        auto find = [&](int x)
        {
            return (x > 0 && x <= n);
        };
        for(int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            while(find(x))    
            {
                int y = nums[x - 1];
                nums[x - 1] = 1e9;
                x = y;
            }
        }

        int ans = n + 1;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != 1e9)  
            {
                return (i + 1);
            }
        }
        return ans;
    }
};