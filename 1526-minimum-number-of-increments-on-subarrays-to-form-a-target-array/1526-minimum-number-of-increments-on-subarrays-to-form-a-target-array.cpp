class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0, cur = 0;
        for(int i = 0; i < target.size(); i++)
        {
            ans += max((target[i] - cur), 0);
            cur = target[i];
        }
        return ans;
    }
};