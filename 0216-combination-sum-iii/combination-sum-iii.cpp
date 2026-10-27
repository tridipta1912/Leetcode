class Solution {
public:
    vector<vector<int>> sex;

    void generate(vector<int>& nums, int k, int n, vector<int>& x, int i, int sum) {
        
        if(x.size()==k)
        {
            if(sum==n)  sex.push_back(x);

            return;
        }
        if(i==9)    return;
        
        generate(nums, k, n, x, i + 1, sum);


        x.push_back(nums[i]);
        sum+=nums[i];
        generate(nums, k, n, x, i + 1, sum);
        x.pop_back();
        sum-=nums[i];
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> x = {};
        generate(v, k, n, x, 0, 0);
        return sex;
    }
};
