class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for(auto x : s)
        {
            if(x == '(') low++, high++;
            else if (x == ')')
            {
                low--, high--;
            }
            if(high < 0)    return false;
            if(x == '*')
            {
                low--;
                high++;
            }
            low = max(low, 0);
        }
        return (low == 0);
    }
};