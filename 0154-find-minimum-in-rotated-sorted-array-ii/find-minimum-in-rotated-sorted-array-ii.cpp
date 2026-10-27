class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int L = 0;
        int R = nums.size() - 1;
        int M;
        int m = 5001;
        if(nums.size()==1)  return nums[0];
        if(nums.size()==2)  return min(nums[0],nums[1]);
        while(R-L>1)
        {
            M = L + (R-L)/2;
            m = min(nums[M],m);
            m = min(nums[M+1],m);
            if(nums[M]<nums[R])  R =  M - 1;
            else if(nums[M]>nums[R])   L = M + 1;
            else    R--;   
        }
        m = min(nums[L],m);
        m = min(nums[R],m);

        return m;
    }
};