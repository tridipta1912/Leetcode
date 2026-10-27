#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/hash_policy.hpp>

#define ll long long
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
#define lcm(x,y)	x*y/__gcd(x,y)

#define f(i,a,b)    for(ll i = a;i<b;i++)
#define fc(i,a,b,c)  for(ll i = a;i<b;i+=c)
#define fi(i,a,b)   for(ll i = a;i>=b;i--)

const int MOD = 1e9+7; // 998244353;
const int N = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem

constexpr ll bct(ll x) { return __builtin_popcountll(x); } // # of bits set
constexpr ll bsz(ll x) { return x == 0 ? 0 : 31-__builtin_clzll(x); } // floor(log2(x))
constexpr ll pow2(ll x) { return 1LL<<x; }
constexpr ll msk2(ll x) { return pow2(x)-1LL; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

#define vv(type, name, h, w, val) \
vector<vector<type>> name(h, vector<type>(w, val))

#define vvv(type, name, length, breadth, depth, val) \
vector<vector<vector<type>>> name(length, vector<vector<type>>(breadth, vector<type>(depth, val)))

using namespace std;
using namespace __gnu_pbds;

template<typename T> using pq = priority_queue<T>; 
template<typename T> using qp = priority_queue<T,vector<T>,greater<T>>; 
template<typename T> using V = vector<T>; 

template<typename T>void outs(T &v,ll h,ll w,string sv=" "){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void outs(T &v,ll n,string sv=" "){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
template<typename T>void outs(vector<T>&v){outs(v,v.size());}
template<typename T>void outs(set<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T>void outs(vector<vector<T>>&v){for(auto &vv:v)outs(vv,vv.size());}
template<typename T>void outs(stack<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void outs(queue<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop();}cout<<endl;}
template<typename T>void outs(deque<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop_front();}cout<<endl;}
template<typename T> void outs(pq<T> st) { while (!st.empty()) { cout << st.top() << " "; st.pop(); } cout << endl; } 
template<typename T> void outs(qp<T> st) { while (!st.empty()) { cout << st.top() << " "; st.pop(); } cout << endl; }
template<typename T>void outs(multiset<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T,size_t size>void outs(array<T, size> &a){for(auto z:a)cout<<z<<" ";cout<<endl;}
template<typename T,typename V>void outs(map<T,V>&v){for(auto z:v)cout<<"["<<z.first<<"]="<<z.second<<",";cout<<endl;}
template <typename T, typename V> void outs(gp_hash_table<T, V> &ht) { for (auto &z : ht) cout << "[" << z.first << "]=" << z.second << ", "; cout << endl; }
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
struct chash { const uint64_t C = uint64_t(2e18 * PI) + 71; const uint32_t RANDOM = chrono::steady_clock::now().time_since_epoch().count(); size_t operator()(uint64_t x) const { return __builtin_bswap64((x ^ RANDOM) * C); }};

template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T summ(const vector<T>&v){return accumulate(v.begin(),v.end(),T(0));};
template<typename T>T rev(const T &v){return T(v.rbegin(),v.rend());};

template <typename T> ll _lb(vector<T>& vec, T& value) { return distance(vec.begin(), lower_bound(vec.begin(), vec.end(), value));}
template <typename T> ll _ub(vector<T>& vec, T& value) { return distance(vec.begin(), upper_bound(vec.begin(), vec.end(), value));}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}
void found(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_mset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//*find_by_order, *order_of_key
//Check: Binary Search & DP


class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) 
    {
        for(auto &nums: hours)   nums%=24;

        ump<long long,long long> mp;

        long long count = 0;
        for(auto nums: hours)   
        {
            count+=(mp[(24-nums)%24]);
            mp[nums]++;
        }
        return count;
    }
};