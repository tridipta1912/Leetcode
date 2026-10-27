class Solution {
public:
    bool sumGame(string num) {
        using ll = long long;
        ll diff = 0;
        ll n = (num.length());
        ll r = (n / 2);
        ll cnt = 0;
        for(ll i = 0; i < r; i++)
        {
            if(num[i] != '?') diff -= (num[i] - '0');
            else              cnt--;
        }
        for(ll i = r; i < n; i++)
        {
            if(num[i] != '?') diff += (num[i] - '0');
            else              cnt++;
        }
        cout << cnt << ' ' << diff << endl;
        if(cnt == 0)
        {
            return (diff != 0);
        }
        if(cnt * diff > 0)  return true;
        cnt = abs(cnt);
        diff = abs(diff);
        ll turns = (cnt + 1) / 2;
        if(cnt == 1)    return true;
        if(9 * (cnt / 2) < diff)    return true;
        if(9 * turns > diff)    return true;
        return false;
    }
};