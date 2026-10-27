class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> arr;
        for(int i = 0; i < matrix.size(); i++)  arr.push({matrix[i][0], i, 0});
        while(k > 1)
        {
            auto [val, i, j] = arr.top();
            arr.pop();
            if(j + 1 < matrix[0].size()) arr.push({matrix[i][j + 1], i, j + 1});
            k--;
        }

        return arr.top()[0];
    }
};