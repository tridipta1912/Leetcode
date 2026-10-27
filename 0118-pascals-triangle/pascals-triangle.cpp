class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        while(ans.size() < numRows)
        {
            vector<int> rows(ans.size() + 1);
            rows[0] = 1;
            rows.back() = 1;
            for(int i = 1; i < rows.size() - 1; i++)    rows[i] = ans.back()[i - 1] + ans.back()[i];
            ans.push_back(rows);
        }
        return ans;
    }
};