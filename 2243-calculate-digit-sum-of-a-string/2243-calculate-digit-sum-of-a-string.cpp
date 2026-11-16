class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k)
        {
            string ns = "";
            int n  = s.length();
            int ptr = 0;
            while(ptr < n)
            {
                int val = 0;
                int nxt = min(n, ptr + k);
                for(int i = ptr; i < nxt; i++)
                {
                    val += (s[i] - '0');
                }
                ptr = nxt;
                ns += to_string(val);
            }
            swap(ns, s);
        }
        return s;
    }
};