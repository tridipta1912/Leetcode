class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int L = 0, R = 1e9;
        int ans = 0;
        auto func = [&](int x)
        {
            int cur = 1, pos = position[0];
            for(int i = 1; i < position.size(); i++)
            {
                if(position[i] - pos >= x)
                {
                    cur++;
                    pos = position[i];
                }
            }
            return (cur >= m);
        };
        while(L <= R)
        {
            int M = L + (R - L) / 2;
            if(func(M))
            {
                ans = M;
                L = M + 1;
            }
            else
            {
                R = M - 1;
            }
        }

        return ans;
    }
};