class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<vector<int>> pref(nums.size(), vector<int>(32, 0));
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < 32; j++)
            {
                if((nums[i] & (1 << j)))    pref[i][j]++;
                if(i > 0)                pref[i][j] += pref[i - 1][j];
            }
        }
        auto query = [&](int l, int r)
        {
            int val = 0;
            for(int i = 0; i < 32; i++)
            {
                int L = (l == 0 ? 0 : pref[l - 1][i]);
                int R = pref[r][i];
                if(L != R)  val += (1 << i);
            }
            return val;
        };

        vector<int> ans;

        for(int i = 0; i < nums.size(); i++)
        {
            int maxx = query(i, nums.size() - 1);
            int L = i, R = nums.size() - 1;
            int idx = 0;
            while(L <= R)
            {
                int M = L + (R - L) / 2;
                if(query(i, M) == maxx)
                {
                    idx = M;
                    R = M - 1;
                }
                else
                {
                    L = M + 1;
                }
            }
            ans.push_back(idx - i + 1);
        }
        return ans;
    }
};