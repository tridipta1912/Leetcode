class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> st;
        sort(candidates.begin(), candidates.end());
        function<void(int, int, vector<int>&)> dfs = [&](int idx, int sum, vector<int>& arr) {
            if (sum == target) 
            {
                st.push_back(arr);
                return;
            }
            if(sum > target) return;
            
            for(int i = idx; i < candidates.size(); i++)
            {
                if(i > idx && candidates[i] == candidates[i - 1])   continue;
                arr.push_back(candidates[i]);
                dfs(i + 1, sum + candidates[i], arr);
                arr.pop_back();
            }
        };

        vector<int> temp;
        dfs(0, 0, temp);
        return st;
    }
};
