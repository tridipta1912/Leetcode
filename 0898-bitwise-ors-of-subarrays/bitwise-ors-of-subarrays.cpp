class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        vector<vector<int>> bitt(32);
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 32; j++)
            {
                if((arr[i] & (1 << j)))   bitt[j].push_back(i);
            }
        }
        unordered_set<int> st;
        for(int i = 0; i < n; i++)
        {
            st.insert(arr[i]);
            int cur = arr[i];
            int idx = i;
                
            while(idx < n)
            {
                int minn = n;
                for(int j = 0; j < 32; j++)
                {
                    if(cur & (1 << j))  continue;
                    auto it = upper_bound(bitt[j].begin(), bitt[j].end(), idx);
                    if(it != bitt[j].end())    minn = min(minn, *it);
                }
                if(minn < n)
                {
                    idx = minn;
                    cur |= arr[minn];
                    st.insert(cur);
                }
                else
                {
                    break;
                }
            }
        }
        return st.size();
    }
};