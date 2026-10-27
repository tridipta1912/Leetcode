class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans = 0;
        
        auto find = [&](vector<int> &a)
        {
            vector<int> st;
            for(auto &x : a)
            {
                auto it = upper_bound(st.begin(), st.end(), x);
                if(it == st.end())  st.push_back(x);
                else
                {
                    *it = x;
                }
            }
            return static_cast<int>(st.size());
        };

        vector<vector<int>> a(k);
        for(int i = 0; i < arr.size(); i++)  a[i % k].push_back(arr[i]);
        for(int i = 0; i < k; i++)
        {
            ans += (a[i].size() - find(a[i]));
        }

        return ans;
    }
};