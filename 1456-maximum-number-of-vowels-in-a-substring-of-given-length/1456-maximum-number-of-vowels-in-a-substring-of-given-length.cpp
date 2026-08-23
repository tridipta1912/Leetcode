class Solution {
public:
    int maxVowels(string s, int k) {
        using ll = long long;
        ll n = s.length();
        vector<ll> arr(n);
        ll ans = 0;
        for(ll i = 0; i < s.length(); i++)
        {
            arr[i] += (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u');
            if(i)   arr[i] += arr[i - 1];
            if(i >= k - 1)  ans = max(ans, arr[i] - (i == k - 1 ? 0 : arr[i - k]));
        }   
        return ans;
    }
};