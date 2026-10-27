class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        using ll = long long;
        ll ans= 0, cur = 0;
        for(ll i = 0; i < flowerbed.size(); i++)
        {
            if(flowerbed[i])    ans += ((cur + 1) / 2), cur = 0;
            else
            {
                if(i && flowerbed[i - 1])    continue;
                if(i + 1 < flowerbed.size() && flowerbed[i + 1])    continue;
                else
                {
                    cur++;
                }
            }
        }
        ans += (cur + 1) / 2;
        return (ans >= n);
    }
};