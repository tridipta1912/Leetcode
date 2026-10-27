class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<vector<int>,vector<string>> mp;
        for(auto nums: strs)
        {
            vector<int> et(26,0);
            for(auto c: nums)
            {
                et[c - 'a']++;
            }
            mp[et].push_back(nums);
        }
        vector<vector<string>> ans;
        for(auto nums: mp)  ans.push_back(nums.second);
        return ans;
    }
};