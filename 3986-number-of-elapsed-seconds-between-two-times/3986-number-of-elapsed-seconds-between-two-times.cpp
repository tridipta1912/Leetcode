class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        auto def = [&](string x)
        {
            int sec = 0;
            sec += 3600 * (10 * (x[0] - '0') + x[1]);
            sec += 60 * (10 * x[3] + x[4]);
            sec += (10 * x[6] + x[7]);
            return sec;
        };
        
        return def(endTime) - def(startTime);
    }
};