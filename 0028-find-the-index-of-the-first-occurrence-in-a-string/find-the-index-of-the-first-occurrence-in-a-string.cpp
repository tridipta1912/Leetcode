class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.length();
        int n2 = needle.length();
        string s3 = "";
        for(int i = 0;i<n1;i++)
        {
            if(s3.length()<n2)
                s3 = s3 + haystack[i];
            else
            {
                s3.erase(s3.begin()+0);
                s3 = s3 + haystack[i];
            }
            if(s3 == needle)
                return (i-n2+1);
        }
        return -1;
    }
};