class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            int cur = 9;
            for(int j = 0; j < i; j++)
            {
                cur *= (9 - j);
            }
            count += cur;
        }
        return count + 1;
    }
};