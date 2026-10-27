class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        for(int rows = 0; rows < box.size(); rows++)
        {
            int n = box[rows].size();
            int count = 0;
            for(int i = 0; i < n; i++)
            {
                if(box[rows][i] == '#')  box[rows][i] = '.', count++;
                if(box[rows][i] == '*')
                {
                    int idx = i;
                    while(count > 0)  box[rows][--idx] = '#', count--;
                }   
            }
            int idx = n - 1;
            while(count > 0)  box[rows][idx--] = '#', count--;
        }
        int rows = box.size();
        int cols = box[0].size();
        vector<vector<char>> rotatedBox(cols, vector<char>(rows, '.'));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rotatedBox[j][rows - i - 1] = box[i][j];
            }
        }
        return rotatedBox;
    }
};