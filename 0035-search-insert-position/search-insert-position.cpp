class Solution {
public:
    int searchInsert(vector<int>& a, int target) 
    {
        int L = 0;
        int R = a.size() - 1;
        int M;
        while(L<=R)
        {
            M = (L + R)/2;
            if(a[M]==target)    return M;

            if(a[M]>target)     R = M - 1;
            if(a[M]<target)     L = M + 1;
        }
        
        return (L);
    }
};