class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> st;

        function<void(int, vector<int>&)> dfs = [&](int sum, vector<int>& arr) {
            if (sum == target) {
                vector<int> temp = arr;
                sort(temp.begin(), temp.end());
                st.insert(temp);
                return;
            }
            for (auto num : candidates) {
                if (sum + num > target) continue;
                arr.push_back(num);
                dfs(sum + num, arr);
                arr.pop_back();
            }
        };

        vector<int> temp;
        dfs(0, temp);

        return vector<vector<int>>(st.begin(), st.end());
    }
};
