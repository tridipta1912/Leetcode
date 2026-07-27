class NumMatrix {
public:
    vector<vector<int>> P;
    NumMatrix(vector<vector<int>>& matrix) {
        P.resize(matrix.size(), vector<int>(matrix[0].size()));
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                P[i][j] = matrix[i][j];
                if(i == 0 && j == 0)    continue;
                if(i)   P[i][j] += P[i - 1][j];
                if(j)   P[i][j] += P[i][j - 1];
                if(i && j) P[i][j] -= P[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 > row2) swap(row1, row2);
        if(col1 > col2) swap(col1, col2);

        int ans = P[row2][col2];
        if(row1)    ans -= P[row1 - 1][col2];
        if(col1)    ans -= P[row2][col1 - 1];
        if(row1 && col1)    ans += P[row1 - 1][col1 - 1];
        
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */