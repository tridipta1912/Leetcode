class Solution {
public:
    int findLucky(vector<int>& arr) {
        using ll = long long;
        unordered_map<ll,ll> freq;
        for(auto c : arr)
            freq[c]++;

        ll ans = -1;
        for(auto [a, b] : freq)
        {
            if(a == b)  ans = max(ans, a);
        }
        return (int)(ans);
    }
};