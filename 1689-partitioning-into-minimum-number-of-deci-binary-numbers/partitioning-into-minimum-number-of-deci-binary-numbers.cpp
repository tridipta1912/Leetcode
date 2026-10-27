class Solution {
public:
    int minPartitions(string n) {
        char x = '0';
        for(char c:n)
        {
            x = max(x,c);
        }
        int ans = int(x) - int('0');
        return ans;
    }
};