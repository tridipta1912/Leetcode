class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const long long MOD = 1e9 + 7;
        long long minn = 1e18;
        for(long long i = 1; i < complexity.size(); i++)    minn = min(minn, (long long)complexity[i]);
        if(complexity[0] >= minn)
        {
            return 0LL;
        }
        long long ans = 1;
        for(long long i = 1; i + 1 <= complexity.size(); i++)
        {
            ans *= i;
            ans %= MOD;
        }
        return ans;
    }
};