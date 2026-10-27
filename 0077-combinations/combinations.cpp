class Solution {
public:
    vector<vector<int>> x;
    void generate(vector<int> &v,int k,int i, vector<int> &h)
    {
        if(h.size()==k)
        {
            x.push_back(h);
            return;
        }
        if(i==v.size()) return;
        
        generate(v,k,i+1,h);

        h.push_back(v[i]);
        generate(v,k,i+1,h);
        h.pop_back();
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> v (n);
        vector<int> h  ={};
        for(int i = 1;i <= n;i++)   v[i-1] = i;

        generate(v,k,0,h);

        return x;
    }
};