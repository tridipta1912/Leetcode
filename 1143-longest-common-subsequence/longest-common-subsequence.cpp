class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // Ensure that text1 is the shorter one for minimal memory usage
        if (n > m) {
            swap(text1, text2);
            swap(n, m);
        }

        // Use two 1D arrays to store only the current and previous rows
        vector<int> previous(m + 1, 0);
        vector<int> current(m + 1, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    current[j] = previous[j - 1] + 1;
                } else {
                    current[j] = max(previous[j], current[j - 1]);
                }
            }
            // Swap current and previous for the next iteration
            swap(current, previous);
        }

        return previous[m];
    }
};
