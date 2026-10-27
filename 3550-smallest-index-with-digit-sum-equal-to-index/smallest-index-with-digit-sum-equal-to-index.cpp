class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        auto find = [&](int x)
        {
            int ans = 0;
            while(x)
            {
                ans += (x % 10);
                x /= 10;
            }
            return ans;
        };

        for(int i = 0; i < nums.size(); i++)
        {
            if(find(nums[i]) == i)  return i;
        }
        return -1;
    }
};