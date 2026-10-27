class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        set<vector<int>> ans;
        for(auto val: nums)
        {
            set<vector<int>> n_ans = ans;
            for(auto arr: ans)  
            {
                if(arr.back() <= val)
                {
                    vector<int> arr1 = arr;
                    arr.push_back(val);
                    n_ans.insert(arr);
                }
            }
            vector<int> to_ins; to_ins.push_back(val);
            n_ans.insert(to_ins);
            swap(ans, n_ans);
        }

        vector<vector<int>> print;
        for(auto arr: ans)  if(arr.size() >= 2) print.push_back(arr);

        return print;
    }
};