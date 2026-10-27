class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> v(3, 0);
        deque<char> dq;
        
        int n = s.length();

        int R = n - 1;
        while(v[0] < k || v[1] < k || v[2] < k)
        {
            if(R < 0)   return -1;
            v[s[R] - 'a']++;
            dq.push_front(s[R]);
            R--;
        }

        cout << dq.size() << endl;

        int ans = dq.size();
        for(int i = 0; i < n; i++)
        {
            v[s[i] - 'a']++;
            while(!dq.empty())
            {
                int l = v[dq.front() - 'a'] - 1;
                if(l >= k)
                {
                    v[dq.front() - 'a']--;
                    dq.pop_front();
                }
                else
                {
                    break;
                }
            }
            cout << i << ' ' << dq.size() << endl;
            int val =  (dq.size() + i + 1);
            if(v[0] >= k && v[1] >= k && v[2] >= k) ans = min(ans,val);
        }
        return ans;
    }
};