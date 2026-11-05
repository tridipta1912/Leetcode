class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(auto &x : arr1)
        {
            bool is_good = true;
            for(auto &y : arr2)
            {
                if(abs(x - y) <= d)
                {
                    is_good = false;
                    break;
                }
            }
            ans += (is_good);
        }
        return ans;
    }
};