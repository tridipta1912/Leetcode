class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int cnt = 0;
        vector<int> arr;
        arr.push_back(0);
        for(auto x : s)
        {
            if(x == '1' && arr.back())    arr.push_back(0);
            else if(x == '0')
            {
                arr.back()++;
            }
        }
        if(!arr.back()) arr.pop_back();
        for(int i = 0; i + 1 < arr.size(); i++) cnt = max(cnt, arr[i] + arr[i + 1]);
        cnt += count(s.begin(), s.end(), '1');
        return cnt;
    }
};