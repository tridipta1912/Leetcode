using ll = long long;
class Solution {
public:
    string nearestPalindromic(string n) {
        pair<long long, long long> minn = {2e18, stoll(n)};
        string n1 = n;
        for(int i = -100; i <= 100; i++)
        {
            if(stoll(n) + i < 0)    continue;
            n = to_string(stoll(n1) + i);
            string ans = n;
            for(int i = 0; i <= (n.length() / 2); i++)
            {
                pair<long long, long long> minnx = {2e18, stoll(n1)};
                for(char c = '0'; c <= '9'; c++)
                {
                    if(i == 0 && c == '0')  continue;
                    string ans1 = ans;
                    ans1[i] = c;
                    ans1[n.length() - i - 1] = c;
                    minnx = min(minnx, {abs(stoll(ans1) - stoll(n1)), stoll(ans1)});
                }
                ans = to_string(minnx.second);
            }

            if(ans == n1)
            {
                pair<long long, long long> minnx = {2e18, stoll(n1)};
                for(char c = '0'; c <= '9'; c++)
                {
                    string ans1 = ans;
                    if(c == ans1[(n.length() - 1) / 2]) continue;
                    
                    ans1[(n.length() - 1) / 2] = c;
                    ans1[(n.length() / 2)] = c;
                    minnx = min(minnx, {abs(stoll(ans1) - stoll(n1)), stoll(ans1)});
                }
                ans = to_string(minnx.second);
            }
            minn = min(minn, {abs(stoll(ans) - stoll(n1)), stoll(ans)});
            
            string ans1 = n;
            if(ans1.size() > 1) ans1.erase(0, 1);
            for(int i = 0; i < ans1.length(); i++)  ans1[i] = '9';
            long long diff1 = abs(stoll(ans1) - stoll(n1));
            if(ans1 != n1)   minn = min(minn, {diff1, stoll(ans1)});
            
            string ans2 = n;
            ans2.insert(ans2.begin(), '1');
            for(int i = 1; i < n.length(); i++)  ans2[i] = '0';
            ans2.back() = '1';
            long long diff2 = abs(stoll(ans2) - stoll(n1));
            if(ans2 != n1)   minn = min(minn, {diff2, stoll(ans2)});
        }
        return to_string(minn.second);
    }
};