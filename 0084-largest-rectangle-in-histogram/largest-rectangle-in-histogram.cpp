class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        using ll = long long;
        ll n = heights.size();
        vector<ll> left(n, -1);
        vector<ll> right(n, n);

        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if(!st.empty()) left[i] = st.top();
            st.push(i);
        }
        while(!st.empty())  st.pop();
        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if(!st.empty()) right[i] = st.top();
            st.push(i);
        }

        
        ll ans = 0;
        for(int i = 0; i < n; i++)  
        {
            ll len = ((right[i] - i - 1) + (i - left[i] - 1) + 1);
            ans = max(ans, heights[i] * len);
        }
        return ans;
    }
};