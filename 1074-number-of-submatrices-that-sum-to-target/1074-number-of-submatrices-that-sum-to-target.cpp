class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        using ll = long long;
        ll n = matrix.size();
        ll m = matrix[0].size();

        vector<vector<ll>> matrix1;
        if(m < n)
        {
            matrix1.assign(m, vector<ll>(n, 0));
            for(ll i = 0; i < n; i++)   for(ll j = 0; j < m; j++)   matrix1[j][i] = matrix[i][j];
            swap(m, n);
        }
        else
        {
            matrix1.assign(n, vector<ll>(m, 0));
            for(ll i = 0; i < n; i++)
            {
                for(ll j = 0; j < m; j++)   matrix1[i][j] = matrix[i][j];
            }
        }

        for(ll i = 0; i < m; i++)
        {
            for(ll j = 1; j < n; j++)   matrix1[j][i] += matrix1[j - 1][i];
        }
        ll ans = 0;
        for(ll i = 0; i < n; i++)
        {
            for(ll j = i; j < n; j++)
            {
                vector<ll> st(m);
                for(ll k = 0; k < m; k++)   st[k] = (matrix1[j][k] - (i ? matrix1[i - 1][k] : 0));
                unordered_map<ll, ll> mp;
                mp[0] = 1;
                for(ll k = 0; k < m; k++)   
                {
                    if(k)   st[k] += st[k - 1];
                    ans += mp[st[k] - target];
                    mp[st[k]]++;
                }
            }
        }
        return ans;
    }
};