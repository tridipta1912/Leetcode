class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pref(n);
        pref[0] = arr[0];
        for(int i = 1; i < n; i++)
        {
            pref[i] = arr[i] ^ pref[i - 1];
        }

        vector<int> ans;
        for(auto nums: queries)
        {
            int a = (nums[0] == 0 ? pref[nums[1]] : pref[nums[1]] xor pref[nums[0] - 1]);
            ans.emplace_back(a);
        }

        return ans;
    }
};