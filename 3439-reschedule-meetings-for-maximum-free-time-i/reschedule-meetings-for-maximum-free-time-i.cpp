class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        startTime.push_back(eventTime); 

        vector<int> gaps;
        gaps.push_back(startTime[0]);
        for (int i = 0; i < n; ++i)
        {
            gaps.push_back((i + 1 == n ? eventTime : startTime[i + 1]) - endTime[i]);
        }

        int cur = 0;
        k++;
        for (int i = 0; i < k && i < (int)gaps.size(); ++i)
            cur += gaps[i];

        int ans = cur;

        for (int i = k; i < gaps.size(); ++i)
        {
            cur += gaps[i] - gaps[i - k];
            ans = max(ans, cur);
        }

        return ans;
    }
};