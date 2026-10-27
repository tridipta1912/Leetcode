class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), cmp);
        set<int> days;
        int ans = 0;
        for(int i = 1; i <= 1e5 + 10; i++) days.insert(i);
        for(auto nums: events)
        {
            auto it = days.lower_bound(nums[0]);
            if(*it <= nums[1])
            {
                ans++;
                days.erase(it);
            }
        }
        return ans;
    }
};