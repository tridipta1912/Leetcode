class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for(int i = 0; i + 2 < num.size(); i++)
        {
            if(num[i] == num[i + 1] && num[i + 1] == num[i + 2])
            {
                string val = "";
                val += num[i], val += num[i + 1], val += num[i + 2];
                ans = max(ans, val);
            }
        }
        return ans;
    }
};