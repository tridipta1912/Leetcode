class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        using ll = long long;
        unordered_map<ll, ll> used;
        deque<ll> dq;
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
        {
            while(!dq.empty() && used[s[i] - 'a'])
            {
                used[dq.front()]--;
                dq.pop_front();
            }
            dq.push_back(s[i] - 'a');
            used[s[i] - 'a'] = 1;
            if(dq.size() > ans) ans = dq.size();
        }
        return ans;
    }
};