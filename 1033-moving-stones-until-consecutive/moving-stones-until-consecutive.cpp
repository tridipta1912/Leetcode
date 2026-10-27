class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) 
    {
        if(a > b)   swap(a,b);
        if(b > c)   swap(b,c);
        if(a > b)   swap(a,b);
        int minn = 0;
        minn += ((b - a) > 1);
        minn += ((c - b) > 1);

        if((c - b) == 2 || (b - a) == 2)
        {
            minn = min(minn, 1);
        }

        int maxx = ((b - a - 1) + (c - b - 1));

        vector<int> ans = {minn,maxx};
        return ans;
    }
};