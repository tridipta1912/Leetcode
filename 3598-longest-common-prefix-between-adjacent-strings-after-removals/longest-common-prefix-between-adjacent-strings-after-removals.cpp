class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        auto calc = [&](string &a, string &b) {
            int len = 0;
            for(int i = 0; i < min(a.length(), b.length()); i++) {
                if(a[i] != b[i]) break;
                else len++;
            }
            return len;
        };

        int n = words.size();
        vector<int> pref(n), suff(n);

        for(int i = 1; i < n; i++) {
            pref[i - 1] = calc(words[i - 1], words[i]);
            suff[i - 1] = pref[i - 1];
        }

        for(int i = 1; i < n; i++) {
            pref[i] = max(pref[i], pref[i - 1]);
        }

        for(int i = n - 2; i >= 0; i--) {
            suff[i] = max(suff[i], suff[i + 1]);
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            if(i < n - 1) ans[i] = max(ans[i], suff[i + 1]);
            if(i >= 2) ans[i] = max(ans[i], pref[i - 2]);
            if(i >= 1 && i + 1 < n) ans[i] = max(ans[i], calc(words[i - 1], words[i + 1]));
        }

        return ans;
    }
};
