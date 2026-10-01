class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        
        int max_depth = 0, cur_depth = 0;
        for(int i = 0; i < seq.length(); i++)
        {
            if(seq[i] == '(')  cur_depth++;
            else 
            {
                cur_depth--;
            }  
            max_depth = max(max_depth, cur_depth);
        }
        vector<int> ans(seq.size());
        for(int i = 0; i < seq.length(); i++)
        {
            if(seq[i] == '(') cur_depth++;
            if(cur_depth > (max_depth / 2))    ans[i] = 1;
            if(seq[i] == ')') cur_depth--;
        }

        return ans;
    }
};