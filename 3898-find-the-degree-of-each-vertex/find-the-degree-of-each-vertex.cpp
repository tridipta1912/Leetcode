class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> deg;
        for(auto x : matrix)
        {
            int v = 0;
            for(auto y : x) v += y;
            deg.push_back(v);
        }
        return deg;
    }
};