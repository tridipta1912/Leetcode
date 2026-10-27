class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        using ll = long long;
        ll tot = 0, cnt = 0, ans = (ll)(1e18);
        while(target > 1 && maxDoubles)
        {
            if(target % 2)  
            {
                cnt++, target--;
            }
            target /= 2;
            tot++;
            ans = min(tot + cnt + (target - 1), ans);
            if(tot == maxDoubles)   break;
        }
        ans = min(ans, (tot + cnt + (target - 1)));
        return ans;
    }
};