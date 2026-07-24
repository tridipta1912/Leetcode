class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, int> pre;

        for(auto x : wordList)  pre[x] = -1;
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        pre[beginWord] = 1;
        
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            if(x == endWord)    break;

            for(int i = 0; i < x.length(); i++)
            {
                for(char c = 'a'; c <= 'z'; c++)
                {
                    char tmp = x[i];
                    x[i] = c;
                    if(pre[x] == -1)
                    {
                        pre[x] = y + 1;
                        q.push({x, y + 1});
                    }
                    x[i] = tmp;
                }
            }
        }

        if(pre[endWord] == -1)  return 0;
        return pre[endWord];
    }
};