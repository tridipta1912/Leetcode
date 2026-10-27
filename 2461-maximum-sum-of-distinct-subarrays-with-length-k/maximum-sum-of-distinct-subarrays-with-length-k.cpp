class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        deque<int> dq;
        unordered_map<int,int> mp;
        long long sum = 0;
        long long ans = 0;
        for(int i = 0; i < k; i++)  
        {
            dq.push_back(nums[i]);
            mp[nums[i]]++;
            sum += nums[i];
        }

        if(mp.size() == k)  ans = max(ans, sum);

        for(int i = k; i < nums.size(); i++)
        {
            mp[dq.front()]--;
            if(mp[dq.front()] == 0) mp.erase((dq.front()));
            sum -= dq.front();
            dq.pop_front();
            dq.push_back(nums[i]);
            mp[nums[i]]++;
            sum += nums[i];

            if(mp.size() == k)  ans = max(ans, sum);
        }

        return ans;
    }
};