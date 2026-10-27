class Solution {
public:
    int minAddToMakeValid(string s) {
        int cur = 0;
        int minn = 0;
        for(auto x : s)
        {
            if(x == '(') cur++;
            else if (x == ')')  cur--;
            minn = min(minn, cur);
        }
        cout << cur << ' ' << minn << endl;
        return (cur - 2 * minn);
    }
};