using ll = long long;
class Solution {
public:
    ll removeDuplicates(vector<int>& nums) {
        ll ptr = 1;
        for(ll i = 1; i < nums.size(); i++)
        {
            if(nums[i] != nums[i - 1])
            {
                nums[ptr] = nums[i];
                ptr++;
            }
        }
        return ptr;
    }
};