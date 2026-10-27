class Solution {
public:
    int lengthOfLastWord(string s) {
        int c=0,sum=0;
        for(int i = s.length()-1;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                c=1;
                sum++;
            }
            else if(c==1)
            {
                break;
            }
        }
        return sum;
    }
};