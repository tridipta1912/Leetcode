class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<int> to_remove;
        stack<int> idx;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(') idx.push(i);
            else if (s[i] == ')')
            {
                if(idx.size() == 1) to_remove.push_back(idx.top()), to_remove.push_back(i);
                idx.pop();
            }
        }
        string ans = "";
        int ptr = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(ptr != to_remove.size() && to_remove[ptr] == i)
            {
                ptr++;
                continue;
            }
            ans += s[i];
        }

        return ans;
    }
};