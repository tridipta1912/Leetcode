#include<bits/stdc++.h>
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(auto &v : s)
        {
            if(v == '6')
            {
                v = '9';
                break;
            }
        }
        int k = stoi(s);
        return k;
    }
};