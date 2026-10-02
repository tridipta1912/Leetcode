class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        using ll = long long;
        map<array<long long, 2>, int> mp;
        long long sum = 0;
        long long ans = 0;
        for(int i = 0; i < capacity.size(); i++)
        {
            if(i > 0)
            {
                ans -= ((capacity[i] == 0 && capacity[i - 1] == 0));
                long long a_l = capacity[i];
                long long pref_l = sum - capacity[i];
                ans += mp[{a_l, pref_l}];
            }
            sum += capacity[i];
            mp[{capacity[i], sum}]++;
        }
        return ans;
    }
};