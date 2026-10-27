class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> arr;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            arr.push_back(nums[i]);
        }
        int ans = 0;
        for(int i = 1; i < arr.size() - 1; i++)
        {
            ans += (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]);
            ans += (arr[i] < arr[i + 1] && arr[i] < arr[i - 1]);
        }
        return ans;
    }
};