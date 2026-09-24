class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        using ll = int;
        ll n = original.size();
        vector<ll> diff;
        for(ll i = 1; i < n; i++)   diff.push_back(original[i] - original[i - 1]);

        ll minn = bounds[0][0], maxx = bounds[0][1];
        
        for(ll i = 0; i < n; i++)
        {
            minn = max(minn, bounds[i][0]);
            maxx = min(maxx, bounds[i][1]);
            if(i + 1 < n)
            {
                minn += diff[i];
                maxx += diff[i];
            }
        }

        return max(maxx - minn + 1, 0);
    }
};