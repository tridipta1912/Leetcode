class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> L(n), R(n);

        set<int> st;
        for(auto &x : positions)    
        {
            st.insert(x[0]); 
            st.insert(x[0] + x[1]);
        }
        vector<int> comp(st.begin(), st.end());

        for(int i = 0; i < n; i++)
        {
            L[i] = lower_bound(comp.begin(), comp.end(), positions[i][0]) - comp.begin();
            R[i] = lower_bound(comp.begin(), comp.end(), positions[i][0] + positions[i][1]) - comp.begin();
        }

        int M = comp.size();
        int maxx = 0;
        vector<int> ans;
        vector<int> height(M);
        for(int i = 0; i < n; i++)
        {
            int base = 0;
            for(int j = L[i]; j < R[i]; j++)
            {
                base = max(base, height[j]);
            }
            for(int j = L[i]; j < R[i]; j++)
            {
                height[j] = base + positions[i][1];
                maxx = max(maxx, height[j]);
            }
            ans.push_back(maxx);
        }

        return ans;
    }
};