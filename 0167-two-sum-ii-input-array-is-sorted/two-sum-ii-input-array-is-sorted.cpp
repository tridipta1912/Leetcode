class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) 
    {
        int L = 0;
        int R = arr.size() - 1;
        while(L<R)
        {
            if(arr[L] + arr[R] == target)   return {L+1,R+1};

            if(arr[L] + arr[R] < target)    L++;

            if(arr[L] + arr[R] > target)    R--;
        }
        return {-1};
    }
};