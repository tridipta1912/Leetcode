struct Node
{
    bool isEnd;
    Node* child[26];
    Node()
    {
        isEnd = false;
        fill(begin(child), end(child), nullptr);
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Node *root = new Node();
        for(auto x : dictionary)
        {
            Node *cur = root;
            for(auto c : x)
            {
                if(!cur->child[c - 'a'])    cur->child[c - 'a'] = new Node();
                cur = cur->child[c - 'a'];
                if(cur->isEnd)  break;
            }
            cur->isEnd = true;
        }
        auto find = [&](string &x)
        {
            Node *cur = root;
            string t = "";
            for(auto c : x)
            {
                if(!cur->child[c - 'a'])    return x;
                cur = cur->child[c - 'a'];
                t += c;
                if(cur->isEnd)  return t;
            }
            return x;
        };
        string ans = "", cur = "";
        sentence += ' ';
        for(auto x : sentence)
        {
            if(x == ' ')
            {
                ans += find(cur);
                ans += ' ';
                cur = "";
            }
            else
            {
                cur += x;
            }
        }
        ans.pop_back();
        return ans;
    }
};