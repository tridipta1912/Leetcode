class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        using ll = long long;
        function<char(ll)> dfs = [&](ll k)
        {
            if(k < 1)  return 'a';
            ll turn = log2(k);
            ll prev = k - (1LL << turn);
            char cur = dfs(prev);
            if(operations[turn] == 1)   cur = char((cur - 'a' + 1) % 26 + 'a');
            return cur;
        };

        return dfs(k - 1);
    }
};