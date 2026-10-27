class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) 
    {
        sort(meetings.begin(), meetings.end());
        int cur = 1;
        int ans = 0;

        for(auto nums : meetings)
        {
            int x = nums[0];
            int y = nums[1];
            ans += max((x - cur), 0);
            cur = max(y + 1, cur);
        }

        ans += max((days + 1 - cur), 0);

        return ans;
    }
};