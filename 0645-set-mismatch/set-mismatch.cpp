class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        using ll = long long;
        ll s1 = 0, s2 = 0;
        for(ll i = 0; i < nums.size(); i++)    
        {
            s1 += nums[i];
            s2 += (nums[i] * nums[i]);
            s1 -= (i + 1);
            s2 -= (i + 1) * (i + 1);
        }
        s2 /= s1;
        vector<int> ans;
        ans.push_back((s2 + s1) / 2);
        ans.push_back((s2 - s1) / 2);
        return ans;
    }
};