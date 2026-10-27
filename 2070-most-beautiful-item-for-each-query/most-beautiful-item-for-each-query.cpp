class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        map<int,int> max_beauty;

        int maxx = 0;
        for(int i = 0; i < items.size(); i++)
        {
            maxx = max(maxx, items[i][1]);
            max_beauty[items[i][0]] = maxx;
        }

        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); i++)
        {
            auto it = max_beauty.upper_bound(queries[i]);
            if(it == max_beauty.begin())
            {
                ans[i] = (0);
                continue;
            }
            it--;
            ans[i] = ((*it).second);
        }
        return ans;
    }
};