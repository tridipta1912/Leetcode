class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        n *= 2;
        int M = (1 << n);
        for(int i = 0; i < M; i++)
        {
            if(__builtin_popcount(i) == (n / 2))
            {
                int cur = 0;
                string possible = "";
                for(int j = 0; j < n; j++)
                {
                    if((i >> j) & 1)    possible += '(', cur++;
                    else
                    {
                        if(cur == 0)    
                        {
                            break;
                        }
                        cur--;
                        possible += ')';
                    }
                }
                if(possible.size() == n)    ans.push_back(possible);
            }
        }
        return ans;
    }
};