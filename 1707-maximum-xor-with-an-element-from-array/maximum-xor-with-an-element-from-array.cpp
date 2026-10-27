using ll = int;
struct Node
{
    Node *child[2];
    Node()
    {
        fill(begin(child), end(child), nullptr);
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        for(ll i = 0; i < queries.size(); i++)
        {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [&](vector<int> &a, vector<int> &b)
        {
            return (a[1] < b[1]);
        });

        Node *root = new Node();
        ll n = nums.size();
        Node *cur = root;

        vector<int> ans(queries.size());
        sort(nums.begin(), nums.end(), greater<ll>());

        for(auto x : queries)
        {
            ll val = x[0], maxx = x[1], idx = x[2];
            while(!nums.empty() && nums.back() <= maxx)
            {
                Node *cur = root;
                ll to_add = nums.back();
                nums.pop_back();
                for(ll i = 31; i >= 0; i--)
                {
                    ll val = ((to_add >> i) & 1);
                    if(!cur->child[val])    cur->child[val] = new Node();
                    cur = cur->child[val];
                }
            }
            if(nums.size() == n)
            {
                ans[idx] = -1;
                continue;
            }
            Node *cur = root;
            ll xorr = 0;
            for(ll i = 31; i >= 0; i--)
            {
                ll bitt = ((val >> i) & 1);
                bitt ^= 1;
                if(cur->child[bitt]) xorr |= (1LL << i), cur = cur->child[bitt];
                else
                {
                    cur = cur->child[(bitt ^ 1)];
                }
            }
            ans[idx] = xorr;
        }
        return ans;
    }
};