class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> x(37);
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            int tt = i;
            int sum = 0;
            while(tt > 0)
            {
                sum += (tt % 10);
                tt /= 10;
            }

            x[sum]++;
            ans = max(ans, x[sum]);
        }

        int cnt = 0;
        for(auto nums : x)
        {
            cnt += (nums == ans);
        }

        return cnt;
    }
};