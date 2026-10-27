class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        bool b = false;
        int pt = digits.size() - 1;
        while(!b && pt >= 0)
        {
            digits[pt] += 1;
            digits[pt] = digits[pt] == 10 ? 0 : digits[pt];
            if(digits[pt] > 0)  b = true;
            pt--;
        }
        
        vector<int> ans;

        if(!b)  ans.push_back(1);
        for(auto nums: digits)  ans.push_back(nums);

        return ans;
    }
};