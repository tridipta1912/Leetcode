class Solution {
public:
    string simplifyPath(string path) {
        path += '/';
        vector<string> ans;
        string s = "";
        for(int i = 0; i < path.size(); i++)
        {
            if(path[i] != '/')
            {
                s += path[i];
            }
            else
            {
                if(s.empty() || s == ".")    {s = s;}
                else if (s == "..") 
                {
                    if(!ans.empty())    ans.pop_back();
                }
                else    ans.push_back(s);

                s = "";
            }
        }
        string str = "";
        for(auto v : ans)
        {
            str += '/';
            str += v;
        }
        if(str.empty()) str += '/';
        return str;
    }
};