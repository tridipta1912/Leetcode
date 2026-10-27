class Solution {
public:
    int possibleStringCount(string word) {
        word += " ";
        int ans = 1;
        int cur = 0;
        for(int i = 0; i < word.size(); i++)
        {
            if(i == 0 || (i > 0 && word[i] == word[i - 1]))
            {
                cur++;
            }
            else if (word[i] != word[i - 1])
            {
                ans += (cur - 1);
                cur = 1;
            }
        }
        return ans;
    }
};