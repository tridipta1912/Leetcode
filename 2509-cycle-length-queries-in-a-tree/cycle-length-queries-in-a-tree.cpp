class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> answer;
        for(const auto &x : queries)
        {
            int u = x[0], v = x[1];
            int cur = 1;
            while(u != v)
            {
                if(u > v)   u >>= 1;
                else        v >>= 1;
                cur++;
            }
            answer.push_back(cur);
        }
        return answer;
    }
};