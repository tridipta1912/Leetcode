class Solution {
public:
    int longestValidParentheses(string s) 
    {
        using ll = long long;

        stack<ll> ind;
        ll ans = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(!ind.empty() && s[i] == ')' && s[ind.top()] == '(')
            {
                ind.pop();
                if(!ind.empty())  ans = max(ans, i - ind.top());
                else              ans = max(ans, (ll)(i + 1));
            }
            else
            {
                ind.push(i);
            }
        }
        return ans;
    }
};