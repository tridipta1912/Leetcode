class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code.size());
        int n = code.size();
        for(int i = 0 ; i < code.size() ; i++)
        {
            int sum = 0;
            for(int j = 1; j <= abs(k); j++) 
            {
                if(k > 0)   sum += code[(i + j) % n];
                if(k < 0)   sum += code[(i - j + n) % n];
            }
            ans[i] = sum;
        }
        return ans;
    }
};