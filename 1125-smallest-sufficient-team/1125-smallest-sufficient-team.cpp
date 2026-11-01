class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        using ll = long long;
        unordered_map<string, ll> hash;
        vector<ll> h;
        ll m = req_skills.size();
        ll M = (1LL << m);

        ll cur = 0;
        for(auto &x : req_skills)
        {
            if(!hash.count(x))    hash[x] = cur++;
        }

        vector<ll> dp(M, 1e9), par(M, -1), par1(M, -1);
        for(ll i = 0; i < people.size(); i++)
        {
            ll cur = 0;
            vector<string> x = people[i];
            for(auto &y : x)    
            {
                auto it = hash.find(y);
                if(it != hash.end())    
                {
                    ll p = it->second;  cur |= (1LL << p);
                }
            }
            h.push_back(cur);
        }

        dp[0] = 0;
        for(ll msk = 0; msk < M; msk++)
        {
            if(dp[msk] != 1e9)
            {
                for(ll i = 0; i < people.size(); i++)
                {
                    ll nsk = (msk | h[i]);
                    if(dp[nsk] > dp[msk] + 1)
                    {
                        dp[nsk] = dp[msk] + 1;
                        par[nsk] = i;
                        par1[nsk] = msk;
                    }
                }
            }
        }

        vector<int> ans;

        cur = M - 1;
        while(cur)
        {
            ll ncur = par1[cur];
            ans.push_back(par[cur]);
            cur = ncur;
        }
        return ans;
    }
};