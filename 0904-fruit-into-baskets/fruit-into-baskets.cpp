class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        unordered_map<int,int> m;
        int L = 0, R = 0;
        int ma = 0;
        while(R!=fruits.size())
        {
            m[fruits[R]]++;
            if(m.size()<=2) 
            {
                ma = max(ma,R-L+1);
                R++;
            }
            
            else 
            {
                m[fruits[L]]--;
                if(m[fruits[L]]==0)  m.erase(fruits[L]);
                L++;
                R++;
            }
        }
        return ma;
    }
};