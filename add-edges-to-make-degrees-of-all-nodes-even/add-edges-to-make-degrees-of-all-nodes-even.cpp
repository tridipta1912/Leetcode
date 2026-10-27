class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        using ll = int;
        vector<ll> degree(n);
        vector<vector<ll>> adj(n);
        for(auto x : edges)
        {
            ll u = x[0], v = x[1];
            u--, v--;
            degree[u]++, degree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> odd_degree;
        for(ll i = 0; i < n; i++)
        {
            if(degree[i] & 1)   odd_degree.push_back(i);
        }

        if(odd_degree.size() == 0)  return true;

        auto check = [&](ll u, ll v)
        {
            for(auto x : adj[u])    if(x == v)  return false;
            return true;
        };
        
        if(odd_degree.size() == 2)
        {
            ll u = odd_degree[0], v = odd_degree[1];
            for(ll i = 0; i < n; i++)
            {
                if(u != i && v != i && check(u, i) && check(v, i))  return true;
            }
            return (check(u, v));
        }

        if(odd_degree.size() == 4)
        {
            if(check(odd_degree[0], odd_degree[1]) && check(odd_degree[2], odd_degree[3]))  return true;
            if(check(odd_degree[0], odd_degree[2]) && check(odd_degree[1], odd_degree[3]))  return true;
            if(check(odd_degree[0], odd_degree[3]) && check(odd_degree[1], odd_degree[2]))  return true;
        }

        return false;
    }
};