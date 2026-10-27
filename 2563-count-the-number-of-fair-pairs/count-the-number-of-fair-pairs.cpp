class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long count = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++)
        {
            int L = 0;
            int R = i - 1;
            int left = -1;
            while(L <= R)
            {
                int M = L + (R - L)/2;
                if(nums[M] + nums[i] >= lower)    left = M, R = M - 1;
                else                L = M + 1;
            }

            int right = -1;
            L = 0; 
            R = i - 1;
            while(L <= R)
            {
                int M = L + (R - L)/2;
                int sum = M == 0 ? nums[i] : nums[i] - nums[M - 1];
                if(nums[M] + nums[i] <= upper)    right = M, L = M + 1;
                else                R = M - 1;
            }

            if(left != -1 && right != -1)   count += (right - left + 1);

            cout << left << ' ' << right << endl;
        }
        return count;
    }
};