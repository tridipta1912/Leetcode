class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        stack<int> st;
        for(auto val: nums)
        {
            if(st.empty()) st.push(val);
            else if(st.top() == val)  st.pop();
            else                        st.push(val);
        }

        vector<int> ans;
        while(!st.empty())  
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};