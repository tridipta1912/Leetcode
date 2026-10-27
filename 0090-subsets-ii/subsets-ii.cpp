class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        using ll = long long;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
    
        function<void(ll, vector<int>&)> dfs = [&](ll idx, vector<int> arr)
        {
            ans.push_back(arr);
            for(int i = idx + 1; i < nums.size(); i++)
            {
                if(i > idx + 1 && nums[i] == nums[i - 1])   continue;
                arr.push_back(nums[i]);
                dfs(i, arr);
                arr.pop_back();
            }
        };

        vector<int> arr;
        dfs(-1, arr);
        return ans;
    }
};