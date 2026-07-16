class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        sort(boxTypes.begin(), boxTypes.end(), [&](vector<int> a, vector<int> b)
        {
            return a[1] > b[1];
        });
        for(int i = 0; i < boxTypes.size(); i++)
        {
            ans += min(boxTypes[i][0], truckSize) * boxTypes[i][1];
            truckSize -= min(boxTypes[i][0], truckSize);
        }
        return ans;
    }
};