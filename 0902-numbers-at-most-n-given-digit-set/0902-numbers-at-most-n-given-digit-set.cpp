class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        n = s.size();
        int val1 = 0, val0 = 0;
        reverse(s.begin(), s.end());
        val1 = 1;
        for(int i = n - 1; i >= 0; i--)
        {
            int nval0 = 0, nval1 = 0;
            for(auto x : digits)
            {
                nval0 += val0;
                string y = string(1, s[i]);
                if(x == y)   nval1 += val1;
                else if (x < y)
                {
                    nval0 += val1;
                }
            }
            if(i && digits[0] != "0")   nval0++;
            swap(nval0, val0);
            swap(nval1, val1);
        }

        return (val0 + val1);
    }
};