class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        deque<int> dq;
        unordered_set<int> st;
        int n = nums.size();
        int sum = 0, ans = 0;
        for(int i = 0; i < n; i++)
        {
            dq.push_back(nums[i]);
            sum += nums[i];
            while(st.count(nums[i]))
            {
                sum -= dq.front();
                st.erase(dq.front());
                dq.pop_front();
            }
            st.insert(nums[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};