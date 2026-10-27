class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int last = -1;
        for (auto &nums : intervals)
        {
            if (last >= nums[1])    continue;

            else if (last >= nums[0])   ans.back()[1] = max(ans.back()[1], nums[1]);

            else
            {
                ans.push_back(nums);
            }

            last = ans.back()[1];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
