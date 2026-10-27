class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> k1;
        vector<int> k2;
        vector<int> k;
        for(auto n: nums)  
        {
            if(n>0) k1.push_back(n);

            else    k2.push_back(n);
        } 

        int o = 0, e = 0;
        for(int i = 0;i<(nums.size()/2);i++)
        {
            k.push_back(k1[o]);
            o++;
            k.push_back(k2[e]);
            e++;
        }
        return k;
    }
};