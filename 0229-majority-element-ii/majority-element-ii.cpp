class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int val1 = 0, val2 = 0;
        int k1 = 0, k2 = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(k1 == nums[i])
            {
                val1++;
            }
            else if (k2 == nums[i])
            {
                val2++;
            }
            else if(val1 == 0)
            {
                val1 = 1;
                k1 = nums[i];
            }
            else if (val2 == 0)
            {
                val2 = 1;
                k2 = nums[i];
            }
            else 
            {
                val1--;
                val2--;
            }
        }

        int cnt1 = 0, cnt2 = 0;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            cnt1 += (nums[i] == k1);
            cnt2 += (nums[i] == k2);
        }

        if(cnt1 > (nums.size() / 3))    ans.push_back(k1);
        if(cnt2 > (nums.size() / 3))    ans.push_back(k2);

        return ans;
    }
};