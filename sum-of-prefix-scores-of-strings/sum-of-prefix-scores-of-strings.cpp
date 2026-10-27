struct Node
{
    Node* child[26];
    int val;
    Node()
    {
        fill(begin(child), end(child), nullptr);
        val = 0;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Node *root = new Node();
        for(auto str : words)
        {
            Node *cur = root;
            for(auto c : str)
            {
                if(!cur->child[c - 'a'])    cur->child[c - 'a'] = new Node();
                cur = cur->child[c - 'a'];
                cur->val++;
            }
        }
        vector<int> ans;
        for(auto str : words)
        {
            int sum = 0;
            Node *cur = root;
            for(auto c : str)
            {
                cur = cur->child[c - 'a'];
                sum += cur->val;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};