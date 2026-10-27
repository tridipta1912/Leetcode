#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        using ll = long long;
        const ll MOD = 1e9 + 7;
        ll k = words[0].length();
        ll m = words.size();
        ll window = k * m;
        map<string, ll> hash;

        auto AK = [&]() {
            return ((ll)rand() * rand()) % MOD + 1;
        };

        srand(time(0));
        ll sum = 0;
        for (string& word : words) {
            if (!hash.count(word)) hash[word] = AK();
            sum += hash[word], sum %= MOD;
        }

        vector<int> ans;
        int n = s.length();

        for (int offset = 0; offset < k; offset++) {
            vector<ll> vals;
            for (int i = offset; i + k <= n; i += k) {
                string w = s.substr(i, k);
                vals.push_back(hash.count(w) ? hash[w] : 0);
            }

            int L = vals.size();
            if (L < m) continue;

            ll cur = 0;
            for (int i = 0; i < m; i++) cur += vals[i], cur %= MOD;

            if (cur == sum) ans.push_back(offset);

            for (int i = m; i < L; i++) {
                cur = (cur - vals[i - m] + MOD) % MOD;
                cur = (cur + vals[i]) % MOD;
                if (cur == sum) {
                    int start = offset + (i - m + 1) * k;
                    ans.push_back(start);
                }
            }
        }

        return ans;
    }
};
