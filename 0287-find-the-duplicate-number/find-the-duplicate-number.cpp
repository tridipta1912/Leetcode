class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        unordered_map<int,int> m;

        for(auto n: nums)   
        {
            m[n]++;
            if(m[n]>=2)  return n;
        }

        return 0;
    }
};