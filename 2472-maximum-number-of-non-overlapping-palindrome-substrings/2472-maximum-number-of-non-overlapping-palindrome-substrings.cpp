class Solution {
public:
    int maxPalindromes(string s, int k) {
        using ll = int;
        ll n = s.length();
        vector<array<ll, 2>> intervals;
        for(ll i = 0; i < n; i++)
        {
            ll L = i;
            ll R = i;
            while(L >= 0 && R < n && s[L] == s[R])
            {
                if(R - L + 1 >= k)  
                {
                    intervals.push_back({L, R});
                    break;
                }
                L--, R++;
            }
            L = i;
            R = i + 1;
            while(L >= 0 && R < n && s[L] == s[R])
            {
                if(R - L + 1 >= k)  
                {
                    intervals.push_back({L, R});
                    break;
                }
                L--, R++;
            }
        }
        sort(intervals.begin(), intervals.end(), [&](auto &a, auto &b)
        {
            return (a[1] < b[1]);
        });
        ll cnt = 0, maxx = -1;
        for(auto [x, y] : intervals)
        {
            if(maxx < x)
            {
                cnt++;
                maxx = y;
            }
        }
        return cnt;
    }
};