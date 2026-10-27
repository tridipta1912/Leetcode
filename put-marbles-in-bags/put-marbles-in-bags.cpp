class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        using ll = long long;
        int n = weights.size();
        vector<int> arr;
        for(int i = 1; i < n; i++)   arr.push_back(weights[i] + weights[i - 1]);
        sort(arr.begin(), arr.end());

        ll ans = 0;
        for(int i = 0; i + 1 < k; i++)
        {
            ans += (arr[n - 2 - i] - arr[i]);
        }
        return ans;
    }
};