class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int k = 1;
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

        vector<int> prefix = gaps, suffix = gaps;
        for(int i = 1; i < gaps.size(); i++)   prefix[i] = max(prefix[i - 1], gaps[i]);
        for(int i = gaps.size() - 2; i >= 0; i--)   suffix[i] = max(suffix[i + 1], gaps[i]);

        for(int i = 0; i < n; i++)
        {
            bool b = false;
            if(i > 0 && prefix[i - 1] >= (endTime[i] - startTime[i])) b = true;
            if((i + 2) < gaps.size() && suffix[i + 2] >= (endTime[i] - startTime[i]))   b = true;
            if(b)
            {
                if(i + 1 < n)   ans = max(ans, startTime[i + 1] - (i == 0 ? 0 : endTime[i - 1]));
                else            ans = max(ans, eventTime - endTime[i - 1]);
            }
        }

        return ans;
    }
};