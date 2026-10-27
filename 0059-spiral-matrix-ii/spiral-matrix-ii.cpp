class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rows = n;
        int cols = n;
        vector<vector<int>> matrix(n, vector<int>(n,0));
        
        vector<int> dr = {0, 1, 0, -1}; // Row direction
        vector<int> dc = {1, 0, -1, 0}; // Column direction
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int total = rows * cols;
        int r = 0, c = 0, d = 0, k = 1; // Starting position and direction index
        
        for (int i = 0; i < total; ++i) 
        {
            matrix[r][c] = k++;
            visited[r][c] = true;
            
            // Calculate the next position
            int nr = r + dr[d];
            int nc = c + dc[d];
            
            // Check if the next position is valid
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                r = nr;
                c = nc;
            } else {
                // Change direction
                d = (d + 1) % 4;
                r += dr[d];
                c += dc[d];
            }
        }
        
        return matrix;
    }
};