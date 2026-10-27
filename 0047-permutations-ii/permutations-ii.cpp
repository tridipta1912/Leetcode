class Solution {
public:

    set<vector<int>> answer;

    void generate(vector<int> nums, int i)
    {
        if(i==nums.size())
        {
            return;
        }
        if(i==nums.size())  return;

        for(int j = i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            answer.insert(nums);
            generate(nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        generate(nums,0);
        vector<vector<int>> k;

        for(auto num: answer)    k.push_back(num);
        return k;
    }
};