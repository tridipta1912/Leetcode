class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
                
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[1] < b[1];
        });

        int cnt = 0, lst = -1e9;

        for(auto len : intervals)
        {
            if(len[0] >= lst)    cnt++, lst = len[1];
        }

        return (intervals.size() - cnt);
    }
};