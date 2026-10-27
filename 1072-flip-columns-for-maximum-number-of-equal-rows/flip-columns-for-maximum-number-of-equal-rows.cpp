class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<vector<int>,int> hash;

        int count = 0;
        for(auto nums: matrix)
        {
            hash[nums]++;
            vector<int> comp(matrix[0].size());
            for(int i = 0; i < matrix[0].size(); i++) comp[i] = ((nums[i] + 1) & 1);
            count = max(count, hash[nums] + hash[comp]);
        }

        return count;
    }
};