class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans1 = 0;
        stack<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'b' && !st.empty() && st.top() == 'a')
            {
                st.pop();
                ans1 += x;
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ns = "";
        while(!st.empty())  ns += st.top(), st.pop();
        reverse(ns.begin(), ns.end());
        for(int i = 0; i < ns.length(); i++)
        {
            if(ns[i] == 'a' && !st.empty() && st.top() == 'b')
            {
                st.pop();
                ans1 += y;
            }
            else
            {
                st.push(ns[i]);
            }
        }
        while(!st.empty())st.pop();
        int ans2 = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a' && !st.empty() && st.top() == 'b')
            {
                st.pop();
                ans2 += y;
            }
            else
            {
                st.push(s[i]);
            }
        }
        ns = "";
        while(!st.empty())  ns += st.top(), st.pop();
        reverse(ns.begin(), ns.end());
        for(int i = 0; i < ns.length(); i++)
        {
            if(ns[i] == 'b' && !st.empty() && st.top() == 'a')
            {
                st.pop();
                ans2 += x;
            }
            else
            {
                st.push(ns[i]);
            }
        }
        
        return max(ans1, ans2);
    }
};