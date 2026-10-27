using ll = int;

struct Trie
{
    Trie* child[2];
    ll cnt;

    Trie() : cnt{0}
    {
        fill(begin(child), end(child), nullptr);
    }
};

class Solution {
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        Trie* root = new Trie();
        ll n = parents.size();
        vector<vector<ll>> adj(n);
        ll sr = 0;

        for(ll i = 0; i < n; i++)
        {
            ll u = i, v = parents[i];
            if(v == -1) sr = i;
            else adj[v].push_back(u);
        }

        ll m = queries.size();
        vector<ll> ans(m);
        vector<vector<array<ll, 2>>> store(n);

        for(ll i = 0; i < m; i++)
            store[queries[i][0]].push_back({queries[i][1], i});

        auto dfs = [&](this auto& self, ll u) -> void
        {
            Trie *cur = root;

            for(ll i = 17; i >= 0; i--)
            {
                ll val = ((u >> i) & 1);
                if(!cur->child[val]) cur->child[val] = new Trie();
                cur = cur->child[val];
                cur->cnt++;
            }

            for(auto v : adj[u])
                self(v);

            for(auto [val, idx] : store[u])
            {
                Trie *cur = root;
                ll answer = 0;

                for(ll i = 17; i >= 0; i--)
                {
                    ll r = ((val >> i) & 1);
                    r ^= 1;

                    if(cur->child[r] && cur->child[r]->cnt > 0)
                        cur = cur->child[r], answer |= (1 << i);
                    else
                        r ^= 1, cur = cur->child[r];
                }

                ans[idx] = answer;
            }

            cur = root;

            for(ll i = 17; i >= 0; i--)
            {
                ll val = ((u >> i) & 1);
                cur = cur->child[val];
                cur->cnt--;
            }
        };

        dfs(sr);

        return ans;
    }
};
