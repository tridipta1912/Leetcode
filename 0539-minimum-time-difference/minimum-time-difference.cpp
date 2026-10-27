class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int minn = 1e9;

        auto findTime = [&](string &s)
        {
            int hr = (s[0] - '0')*10 + (s[1] - '0');
            int min = (s[3] - '0')*10 + (s[4] - '0');
            return (hr*60 + min); 
        };

        for(int i = 0 ; i < timePoints.size() - 1; i++)
        {
           cout << findTime(timePoints[i]) << endl;
           minn = min(findTime(timePoints[i + 1]) - findTime(timePoints[i]), minn);
        }
        minn = min(1440 - findTime(timePoints.back()) + findTime(timePoints.front()), minn);
        return minn;
    }
};