class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        constexpr int MOD = 1e9 + 7;
        long long ans = 0;
        array<int, 2> cnt = {1, 0};
        int sum = 0;
        for(auto &x : arr)
        {
            sum += x, sum %= 2;
            ans += cnt[1 ^ sum]; ans %= MOD;
            cnt[sum]++;
        }
        return static_cast<int>(ans);
    }
};