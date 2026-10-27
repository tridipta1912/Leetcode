class Solution {
public:
    string intToRoman(int num) 
    {
        vector <int> n = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string s="";
        vector <string> str = {"I","IV","V","IX","X","XL","L","XC","C", "CD","D","CM","M"};
        for(int i = n.size()-1; i>=0 ; i--)
        {
            while(num>=n[i])
            {
                s = s + str[i];
                num = num - n[i];
            }
        }
        return s;
    }
};