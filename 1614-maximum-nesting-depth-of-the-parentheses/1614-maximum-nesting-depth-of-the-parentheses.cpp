class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int cur = 0;
        for(char &x : s)
        {
            if(x == '(')    cur++;
            else if (x == ')')  cur--;
            ans = max(ans, cur);
        }
        return ans;
    }
};