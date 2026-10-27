class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        map<int,int> m;
        int max = 0;
        int c = 0;
        for(auto n:nums)
        {
            m[n]++;
            if(m[n]>max)
            {
                max = m[n];
                c = 0;
            }
            if(m[n]==max)   c++;
        }
        int ans = max * c;
        return ans;
    }
};