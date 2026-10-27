class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        set<int> ne;
        int n = nums.size();
        
        function<void(set<int>&, vector<int>&)> dfs = [&](set<int> nott, vector<int> arr)
        {
            set<int> tmp = nott;
            for(auto idx : nott)
            {
                tmp.erase(idx);
                arr.push_back(nums[idx]);
                dfs(tmp, arr);
                tmp.insert(idx);
                arr.pop_back();
            }
            if(nott.empty())
            {
                ans.push_back(arr);
            }
        };

        for(int i = 0; i < nums.size(); i++)    ne.insert(i);
        vector<int> temp;
        dfs(ne, temp);
        return ans;
    }
};