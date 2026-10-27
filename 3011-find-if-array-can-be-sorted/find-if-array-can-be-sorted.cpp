class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> ans, same;
        for(auto val : nums)
        {
            if(same.empty())
            {
                same.push_back(val);
            }
            else if (__builtin_popcount(val) == __builtin_popcount(same.back()))
            {
                same.push_back(val);
            }
            else
            {
                sort(same.begin(), same.end());
                for(auto x: same)    ans.push_back(x);
                same.clear();
                same.push_back(val);
            }
        }
        sort(same.begin(), same.end());
        for(auto x: same)    ans.push_back(x);
        //for(auto x: ans)    cout << x << endl;
        bool b = true;
        for(int i = 0 ; i < ans.size() - 1; i++)    b &= (ans[i] <= ans[i + 1]);
        
        return b;
    }
};