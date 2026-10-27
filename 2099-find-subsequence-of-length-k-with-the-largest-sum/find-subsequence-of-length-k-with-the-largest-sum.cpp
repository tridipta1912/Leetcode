class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> arr(n);
        for(int i = 0; i < n; i++)  arr[i] = {nums[i], i};

        sort(arr.begin(), arr.end(), greater<pair<int,int>>());

        multiset<int> mst;
        for(int i = 0; i < k; i++)  mst.insert(arr[i].second);

        vector<int> ans;
        while(!mst.empty())
        {
            ans.push_back(nums[*mst.begin()]);
            mst.erase(mst.begin());
        }

        return ans;
    }
};