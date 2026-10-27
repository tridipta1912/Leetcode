class Solution {
public:
    int bulbSwitch(int n) 
    {
        int count = 0;
        int x = 1;
        for(int i = 1; x <= n; i++)
        {
            x = i * i;
            count += (x <= n);
        }
        return count;
    }
};