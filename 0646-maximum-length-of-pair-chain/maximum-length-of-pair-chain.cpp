class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [&](vector<int> &a, vector<int> &b)
        {
            return (a[1] < b[1]);
        });

        int ans = 0, maxx = -1001;

        for(auto x : pairs)
        {
            if(x[0] > maxx)
            {
                maxx = x[1];
                ans++;
            }
        }

        return ans;
    }
};