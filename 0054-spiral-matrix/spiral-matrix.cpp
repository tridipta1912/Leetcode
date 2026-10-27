class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> result;
        
        // Define the direction vectors for "right, down, left, up"
        vector<int> dr = {0, 1, 0, -1}; // Row direction
        vector<int> dc = {1, 0, -1, 0}; // Column direction
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int total = rows * cols;
        int r = 0, c = 0, d = 0; // Starting position and direction index
        
        for (int i = 0; i < total; ++i) {
            result.push_back(matrix[r][c]);
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
        
        return result;
    }
};
