class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> row(n, vector<bool>(m, false));
        vector<vector<bool>> col(n, vector<bool>(m, false));
        vector<vector<bool>> box(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] != '.'){
                    int num = mat[i][j] - '0' - 1;
                    int boxIndex = i/3*3 + j/3;
                    if(row[i][num] || col[j][num] || box[boxIndex][num])
                        return false;
                    row[i][num] = col[j][num] = box[boxIndex][num] = true;
                }
            }
        }
        return true;
    }
};