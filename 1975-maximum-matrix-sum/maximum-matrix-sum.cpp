class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long count = 0, sum = 0, minn = 1e9;
        for(auto nums: matrix)
        {
            for(auto val: nums)
            {
                count += (val < 0);
                if(abs(val) < (minn))    minn = abs(val);
                sum += abs(val); 
            }
        }

        if(count % 2 == 0)  return sum;
        else                return (sum - 2 * minn);
    }
};