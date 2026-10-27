class Solution 
{
public:
    int myAtoi(string s) 
    {
        long long int n = 0; 
        long long int n1 = 0;
        int c=0,flag=0,k;
        for(int i=0;i<s.length();i++)
        {
              
            if(s[i]>='0'&& s[i]<='9')
            {
                n = (n*10)+((s[i]-48)*1LL); 
                c=1;
                k=i-1;
            }
            else if (s[i]!=' ' && c==0)
            {
                if((s[i]=='+'||s[i]=='-') && s[i+1]>=48 && s[i+1]<=57)
                {
                    if(s[i]=='-')   flag = 1;
                }
                else break;
            }
            else if (c==1)
                break;
            
            n1 = n;
            if(flag == 1)   n1 = -1*n;

            if(n1>INT_MAX)
            {
                n1=INT_MAX;
                break;
            }

            else if(n1<INT_MIN)
            {
                n1=INT_MIN;
                break;
            }
        }
        
        return n1;
    }
};