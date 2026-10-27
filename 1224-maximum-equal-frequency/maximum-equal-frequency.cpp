class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        using ll = long long;
        unordered_map<ll, ll> mp, freq;
        ll ans = 0, maxx = 0;
        for(ll i = 0; i < nums.size(); i++)
        {
            ll tot_len = i + 1;
            
            if(mp.count(nums[i]))
            {
                freq[mp[nums[i]]]--;
            }
            mp[nums[i]]++;
            maxx = max(maxx, mp[nums[i]]);
            freq[mp[nums[i]]]++;
            
            if(freq[1] == tot_len)  ans = max(ans, tot_len);
            if(freq[1] == 1)
            {
                ll x = maxx;
                ll y = freq[maxx];
                if((x * y) == tot_len - 1)  ans = max(ans, tot_len);        
            }
            if(freq[maxx] == 1)
            {
                ll x = maxx - 1;
                ll y = freq[maxx - 1];
                if((x * y + maxx) == tot_len)   ans = max(ans, tot_len);
            }
        }

        return ans;
    }
};