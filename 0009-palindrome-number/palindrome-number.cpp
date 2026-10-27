class Solution {
public:
    bool isPalindrome(int x) 
    {
        int n =x;
        long int num = 0;
        if(x>=0)
        {
            while(x>0)
            {
                int d = x%10;
                x = x/10;
                num = (num*10) + d;
            }

            if(num == n)    return true;
            else    return false;
        }
        else
            return false;
    }
};