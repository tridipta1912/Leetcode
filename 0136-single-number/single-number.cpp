class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int arr[60001];

        for(int i = 0;i<60001;i++)  arr[i] = 0;

        for(int i = 0;i<nums.size();i++)
        {
            nums[i] = nums [i] + 30000;
            arr[nums[i]]++;
        }

        for(int i = 0;i<60001;i++)
        {
            if(arr[i]==1)   return (i-30000);
        }

        return 1;
    }
};