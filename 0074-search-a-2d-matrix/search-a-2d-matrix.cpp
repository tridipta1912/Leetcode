class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int L = 0, R = matrix.size() - 1,M;
        int c = matrix[0].size();
        int r = matrix.size();
        if(c == 1 && r == 1)
        {
            if(matrix[0][0]==target)    return true;
            else    return false;
        }
        while(L<=R)
        {
            M = L + (R-L)/2;
            if(matrix[M][0]<=target && matrix[M][c-1]>=target)
            {
                break;
            }
            if(matrix[M][0]>target) R = M - 1;
            if(matrix[M][c-1]<target)   L = M + 1;
        }
        if(M>=r || M<0) return false;

        auto it = lower_bound(matrix[M].begin(),matrix[M].end(),target);
        if(it!=matrix[M].end())
        {
            if(*it==target) return true;
        }          
        return false;
    }
};