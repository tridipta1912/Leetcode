class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        using ll = long long;
        unordered_map<ll, ll> left, right;
        unordered_map<ll, ll> cntl, cntr;
        for(int i = 0; i < nums.size(); i++)    right[nums[i]] += i, cntr[nums[i]]++;

        vector<long long> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            right[nums[i]] -= i;
            cntr[nums[i]]--;

            ans.push_back(cntl[nums[i]] * i - left[nums[i]] + right[nums[i]] - cntr[nums[i]] * i);

            left[nums[i]] += i;
            cntl[nums[i]]++;
        }

        return ans;
    }
};