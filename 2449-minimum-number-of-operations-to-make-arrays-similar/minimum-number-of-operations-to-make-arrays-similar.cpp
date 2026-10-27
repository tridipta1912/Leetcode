class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        using ll = long long;
        vector<ll> even_nums, even_target;
        vector<ll> odd_nums, odd_target;

        for(auto x : nums)
        {
            if(x % 2 == 0)  even_nums.push_back(x);
            else            odd_nums.push_back(x);
        }
        for(auto x : target)
        {
            if(x % 2 == 0)  even_target.push_back(x);
            else            odd_target.push_back(x);
        }

        ll ans = 0;
        sort(even_nums.begin(), even_nums.end());
        sort(odd_nums.begin(), odd_nums.end());
        sort(even_target.begin(), even_target.end());
        sort(odd_target.begin(), odd_target.end());

        for(ll i = 0; i < even_nums.size(); i++)
        {
            ans += (abs(even_nums[i] - even_target[i])) / 2;
        }
        for(ll i = 0; i < odd_nums.size(); i++)
        {
            ans += (abs(odd_nums[i] - odd_target[i])) / 2;
        }
        
        return ans / 2;
    }
};