class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        map<int, int> mp;
        set<int> st;

        int n = nums.size();

        for(int x: nums)    st.insert(x);

        deque<int> dq;

        for(int i = 0; i < nums.size(); i++)
        {
            dq.push_back(i);
            mp[nums[i]]++;
            if(mp.size() == st.size())  break;
        }
        int ans = 0;

        if(mp.size() == st.size())  ans += (n - dq.back());

        for(int i = 0; i < nums.size() - 1; i++)
        {
            mp[nums[i]]--;
            if(mp[nums[i]] == 0)    mp.erase(mp.find(nums[i]));

            while((dq.back() < (n - 1)) && mp.size() != st.size())
            {
                dq.push_back(dq.back() + 1);
                mp[nums[dq.back()]]++;
            }

            if(mp.size() == st.size())  ans += (n - dq.back());
        }
        
        return ans;
    }
};