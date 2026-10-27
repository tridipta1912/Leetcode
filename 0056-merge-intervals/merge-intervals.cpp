#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/hash_policy.hpp>

#define ll int
#define db long double

#define pi pair<int,int>
#define pl pair<ll,ll>
#define pd pair<db,db>

#define vi vector<ll>
#define vb vector<bool>
#define vd vector<db>
#define vs vector<string>
#define vpi vector<pi>
#define vpl vector<pl>
#define vpd vector<pd>

#define mp make_pair
#define FF first
#define SS second

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define srt(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define rtn return
#define lb(a,x) lower_bound(all(a),x)
#define ub(a,x) upper_bound(all(a),x)
#define trav(nums,a)    for(auto &nums: a)
#define endl '\n'
#define ump gp_hash_table
#define in(v)    f(i,0,v.size()) cin>>v[i];
#define lcm(x,y)	(x/__gcd(x,y))*y

#define f(i,a,b)    for(ll i = a;i<b;i++)
#define fc(i,a,b,c)  for(ll i = a;i<b;i+=c)
#define fi(i,a,b)   for(ll i = a;i>=b;i--)


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        srt(intervals);

        vector<vector<int>> ans;

        trav(nums, intervals)
        {
            if(ans.size()>0 && ans[ans.size()-1][1] >= nums[0])
            {
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], nums[1]);
            }
            else    
            {
                ans.pb({nums[0],nums[1]});
            }
        }
        return ans;
    }
};