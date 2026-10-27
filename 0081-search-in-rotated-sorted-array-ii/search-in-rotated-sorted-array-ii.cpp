class Solution {
public:
    bool search(vector<int>& arr, int target) 
    {
        int L = 0;
        int R = arr.size() - 1;
        int M;
        int c;
        while(L<=R)
        {
            M = L + (R-L)/2;
            if(arr[M]==target)  return true;

            if(arr[L]==arr[M] && arr[M]==arr[R])  
            {
                L++;
                R--;
                continue;
            }

            if(arr[L] <= arr[M])
            {
                if(arr[L]<=target && arr[M]>=target)    R = M - 1;
                else    L = M + 1;
            }
            else if(arr[M] <= arr[R])
            {
                if(arr[M]<=target && arr[R]>=target) L = M + 1;
                else    R = M - 1;
            }
        }
        //if(L>=0 && arr[L]==target || R>=0 && arr[R]==target)  return true;
        return false;
    }
};