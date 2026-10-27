class Solution {
public:
    bool isValid(string word) {
        bool b = true, vow = false, cons = false;
        vector<char> vo = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(auto c : word)
        {
            if(c >= 'a' && c <= 'z')    {}
            else if(c >= 'A' && c <= 'Z')    {}
            else if(c >= '0' && c <= '9')    {}
            else                        b = false;
            bool k1 = false;
            for(auto tt : vo)   k1 |= (c == tt);
            if(k1)  vow = true;
            else if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))    cons = true;
        }
        return (b & vow & cons && word.length() >= 3);
    }
};