class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(!visited[i][j])  
                {
                    swap(matrix[i][j], matrix[j][i]);
                    visited[i][j] = true;
                    visited[j][i] = true;
                }
            }
        }

        visited.assign(matrix.size(), vector<bool>(matrix[0].size(), false));

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(!visited[i][j])  
                {
                    swap(matrix[i][j], matrix[i][matrix[0].size() - j - 1]);
                    visited[i][j] = true;
                    visited[i][matrix[0].size() - j - 1] = true;
                }
            }
        }
    }
};