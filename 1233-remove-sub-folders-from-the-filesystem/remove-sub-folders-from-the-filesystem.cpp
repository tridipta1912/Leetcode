class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        string last = "&";
        vector<string> ans;
        for(int i = 0; i < folder.size(); i++)
        {
            if(last == folder[i])   continue;
            if((last.length() > folder[i].length()) || folder[i].substr(0, last.length()) != last || (folder[i][last.length()] != '/'))
            {
                ans.push_back(folder[i]);
                last = folder[i];
            }
        }
        return ans;
    }
};