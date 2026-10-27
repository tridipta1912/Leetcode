class Solution {
public:
    int kthFactor(int n, int k) 
    {
        if (n == 1 && k == 1) return 1;

        set<int> factors;
        for(int i = 1; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                int h = n / i;
                factors.insert(i);
                factors.insert(n / i);
            }
        }
        
        auto it = factors.begin();
        
        int ans;

        if(k > factors.size())  return -1;

        while(k--)
        {
            ans = *(it);
            it++;
        }
        return ans;
    }
};
