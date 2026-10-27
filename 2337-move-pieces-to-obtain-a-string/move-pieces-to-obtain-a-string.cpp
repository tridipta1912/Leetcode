class Solution {
public:
    bool canChange(string start, string target) {
        using ll = long long;
        vector<ll> order1, order2;
        for(auto x : start)
        {
            if(x == 'L' || x == 'R')    order1.push_back(x);
        }
        for(auto x : target)
        {
            if(x == 'L' || x == 'R')    order2.push_back(x);
        }
        if(order1.size() != order2.size() || order1 != order2)
        {
            return false;
        }
        vector<ll> start_L, start_R;
        vector<ll> target_L, target_R;

        for(ll i = 0; i < start.size(); i++)
        {
            if(start[i] == 'L') start_L.push_back(i);
            if(start[i] == 'R') start_R.push_back(i);
            if(target[i] == 'L') target_L.push_back(i);
            if(target[i] == 'R') target_R.push_back(i);
        }

        for(ll i = 0; i < start_L.size(); i++)
        {
            if(start_L[i] < target_L[i])    return false;
        }
        for(ll i = 0; i < target_R.size(); i++)
        {
            if(start_R[i] > target_R[i]) return false;
        }
        return true;
    }
};