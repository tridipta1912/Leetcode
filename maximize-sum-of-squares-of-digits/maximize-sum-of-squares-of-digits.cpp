class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while(num--)
        {
            ans += char(min(sum, 9) + '0');
            sum -= min(sum, 9);
        }
        if(sum > 0) return "";
        return ans;
    }
};