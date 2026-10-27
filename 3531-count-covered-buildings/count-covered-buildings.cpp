class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans = 0;
        vector<int> minn_x(1e5+1, 1e6);
        vector<int> minn_y(1e5+1, 1e6);
        vector<int> maxx_x(1e5+1, 0);
        vector<int> maxx_y(1e5+1, 0);
        
        for (const auto nums : buildings)
        {
            minn_x[nums[1]] = min(minn_x[nums[1]], nums[0]);        
            minn_y[nums[0]] = min(minn_y[nums[0]], nums[1]);
            maxx_x[nums[1]] = max(maxx_x[nums[1]], nums[0]);
            maxx_y[nums[0]] = max(maxx_y[nums[0]], nums[1]);
        }

        for (const auto nums : buildings)
        {
            ans += (minn_x[nums[1]] < nums[0] && maxx_x[nums[1]] > nums[0] && 
                    minn_y[nums[0]] < nums[1] && maxx_y[nums[0]] > nums[1]);
        }
        return ans;
    }
};