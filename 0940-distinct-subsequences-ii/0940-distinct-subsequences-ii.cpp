class Solution {
public:
    int distinctSubseqII(string s) {
        using ll = long long;
        constexpr ll MOD = 1e9 + 7;

        ll prev = 1;            // pref[0] = 1 (empty subsequence)
        vector<ll> lst(26, 0);  // stores pref[last[c] - 1]

        for (char c : s) {
            int idx = c - 'a';

            // new_prev = 2 * prev - lst[c]
            ll new_prev = (2 * prev - lst[idx]) % MOD;
            new_prev = (new_prev + MOD) % MOD;

            lst[idx] = prev;
            prev = new_prev;
        }

        // Remove the empty subsequence
        return (prev - 1 + MOD) % MOD;
    }
};