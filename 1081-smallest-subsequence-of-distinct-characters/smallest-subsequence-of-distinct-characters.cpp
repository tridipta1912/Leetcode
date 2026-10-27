class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int> pos(26, -1);
        for(int i = n - 1; i >= 0; i--) 
        {
            if(pos[s[i] - 'a'] == -1) pos[s[i] - 'a'] = i;
        }
        
        vector<int> st;
        vector<int> present(26);
        for(int i = 0; i < n; i++)
        {
            if(present[s[i] - 'a']) continue;
            while(!st.empty() && pos[s[st.back()] - 'a'] > i && s[st.back()] > s[i])     
            {
                present[s[st.back()] - 'a'] = 0, st.pop_back();
            }
            st.push_back(i);
            present[s[i] - 'a'] = 1;
        }

        string ans = "";
        for(int i = 0; i < st.size(); i++)
        {
            ans += s[st[i]];
        }

        return ans;
    }
};