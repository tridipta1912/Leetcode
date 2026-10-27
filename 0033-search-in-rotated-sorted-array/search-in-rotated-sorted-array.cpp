class Solution {
public:
    int search(vector<int>& arr, int target) 
    {
        int L = 0;
        int R = arr.size() - 1;
        int M;
        int c;
        while(L<=R)
        {
            M = L + (R-L)/2;
            //Identify the sorted half
            if(arr[L] <= arr[M])    c = 1;
            else  c = 2;
            if(arr[M]==target)  return M;

            if(c==1)
            {
                if(arr[L]<=target && arr[M]>=target)    R = M - 1;
                else    L = M + 1;
            }
            if(c==2)
            {
                if(arr[M]<=target && arr[R]>=target) L = M + 1;
                else    R = M - 1;
            }
        }
        // if(arr[L] == target)    return L;
        // if(arr[R] == target)    return R;
        return -1;
    }
};