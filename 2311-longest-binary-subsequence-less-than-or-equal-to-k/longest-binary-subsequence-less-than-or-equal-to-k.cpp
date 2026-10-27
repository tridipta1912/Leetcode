class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0;
        long long cur = 0;
        reverse(s.begin(), s.end());
        bool b = false;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '0')   ans++;
            else 
            {
                if(b || i > 40)   continue;
                if((cur + (1LL << i)) <= k) ans++, cur += (1LL << i);
                else                        b = true;
            }
        }
        return ans;
    }
};