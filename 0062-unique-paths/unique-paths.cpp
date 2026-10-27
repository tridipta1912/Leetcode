#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("unroll-loops")
#pragma gcc optimize("Ofast")
#pragma GCC optimization("Ofast")
#pragma optimize(Ofast)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


#define ll long long
#define pb push_back
#define eb emplace_back
#define srt(v) sort(v.begin(), v.end())
#define f(i,a,b)    for(ll i = a;i<b;i++)
#define fc(i,a,b,c)  for(ll i = a;i<b;i+=c)
#define fi(i,a,b)   for(ll i = a;i>=b;i--)
#define vi  vector<ll>
#define pii pair<ll,ll>
#define vpi vector<pair<ll,ll>>
#define vvi vector<vector<ll>>
#define lcm(a,b) (a*b)/__gcd(a,b)
#define in(v)    f(i,0,v.size()) cin>>v[i];
#define outs(v)  f(i,0,v.size()) cout<<v[i]<<" ";
#define outl(v)  f(i,0,v.size()) cout<<v[i]<<endl;
#define all(x)  x.begin(),x.end()
#define mp make_pair
#define be begin()
#define en end()
#define lb lower_bound
#define ub upper_bound
#define pq priority_queue<ll>
#define pqr priority_queue<ll,vector<ll>,greater<ll>>
#define endl '\n'

const ll MOD = 1e9+7;
const double pi = 3.141597653;

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_mset;
//*find_by_order, *order_of_key

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vvi dp(m,vi(n,0));

        dp[0][0] = 1;
        f(i,0,m)
        {
            f(j,0,n)
            {
                ll x = i + 1;
                ll y = j + 1;
                if(x<m) dp[x][j]+=dp[i][j];
                if(y<n) dp[i][y]+=dp[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};