class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> answer;
        int cnt = 0;
        for(auto x : nums)  cnt += (x < target);
        for(auto x : nums)  if(x == target) answer.push_back(cnt++);
        return answer;
    }
};