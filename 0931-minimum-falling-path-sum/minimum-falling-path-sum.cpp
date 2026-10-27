class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        vector<vector<int>> dp=matrix;
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int up=dp[i-1][j];
                int left=INT_MAX; int right=INT_MAX;
                if(j>0) left=dp[i-1][j-1];
                if(j<n-1) right=dp[i-1][j+1];

                dp[i][j]=matrix[i][j]+min({up, left, right});
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};