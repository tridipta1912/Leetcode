/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        sort(words.begin(), words.end());
        while(true)
        {
            int M = rand() % words.size();
            int x = master.guess(words[M]);
            if(x == 6)  break;
            vector<string> n_words;
            for(auto nums: words)
            {
                int count = 0;
                for(int i = 0; i < 6; i++)  count += (nums[i] == words[M][i]);
                if(count == x)  n_words.push_back(nums);
            }
            words.swap(n_words);
        }
    }
};