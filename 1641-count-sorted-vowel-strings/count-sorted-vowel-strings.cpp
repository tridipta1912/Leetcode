#define ll long long
class Solution {
public:
    int countVowelStrings(int n) {
        vector<ll> nums (5,1);
        ll sum = 5;
        for(int i = 2;i<=n;i++)
        {
            sum = 0;
            nums[0] = nums[0] + nums[1] + nums[2] + nums[3] + nums [4];
            nums[1] = nums[1] + nums[2] + nums[3] + nums [4];
            nums[2] = nums[2] + nums[3] + nums [4];
            nums[3] = nums[3] + nums [4];
            nums[4] = nums [4];
            for(int i = 0;i<5;i++)
            {
                sum = sum + nums[i];
            }
        }
        return sum;
    }
};