
class Solution {
public:
    int minSteps(string s, string t) {
        const int k = 26;
        int a[k];
        int b[k];
        for(int i =0;i<26;i++)
        {
            a[i]=0;
            b[i]=0;
        }
        int c = 0; 
        for(int i = 0; i < s.length(); i++)
        {
            int n = int(s[i])-97;
            a[n]++;
            int n1 = int(t[i])-97;
            b[n1]++;
        }
        for(int i = 0; i<26 ; i++)
        {
            if(a[i]>b[i])
            {
                c = c + (a[i]-b[i]);
            }
        }
        return c;
    }
};