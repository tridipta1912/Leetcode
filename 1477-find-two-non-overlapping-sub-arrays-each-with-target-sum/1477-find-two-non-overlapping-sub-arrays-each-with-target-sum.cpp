class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        using ll = int;
        
        auto find = [&](vector<ll> &a)
        {
            ll n = a.size();
            vector<ll> ans(n);
            unordered_map<ll, ll> lst;
            lst[0] = 0;
            ll sum = 0;

            for(ll i = 0; i < n; i++)
            {
                sum += arr[i];
                lst[sum] = i + 1;
                ll val = 1e9;
                if(lst.count(sum - target)) val = (i + 1 - lst[sum - target]);
                if(i)   val = min(val, ans[i - 1]);
                ans[i] = val;
            }

            return ans;
        };

        vector<ll> pref = find(arr);
        reverse(arr.begin(), arr.end());
        vector<ll> suff = find(arr);
        reverse(suff.begin(), suff.end());

        ll ans = 1e9;
        for(ll i = 0; i + 1 < arr.size(); i++)
        {
            if(pref[i] != 1e9 && suff[i + 1] != 1e9)    ans = min(ans, pref[i] + suff[i + 1]);
        }

        return ((ans == 1e9) ? -1 : ans);
    }
};