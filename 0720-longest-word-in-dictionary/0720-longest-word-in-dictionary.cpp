class Solution {
public:
    struct Node
    {
        bool isEnd;
        Node* child[26];
        Node* par;
        char x;
        Node()
        {
            isEnd = false;
            fill(begin(child), end(child), nullptr);
            par = nullptr;
            x = '\0';
        }
    };
    string longestWord(vector<string>& words) {
        using ll = int;
        
        Node* root = new Node();
        for(auto x : words)
        {
            Node* cur = root;
            for(auto c : x) 
            {
                if(cur->child[c - 'a']) cur = cur->child[c - 'a'];
                else
                {
                    cur->child[c - 'a'] = new Node();
                    cur->child[c - 'a']->par = cur;
                    cur = cur->child[c - 'a'];
                    cur->x = c;
                }
            }
            cur->isEnd = true;
        }
        ll ans = 0;
        Node* end = nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* cur = q.front();
            q.pop();
            for(ll i = 25; i >= 0; i--)  
            {
                if(cur->child[i] && cur->child[i]->isEnd)
                {
                    q.push(cur->child[i]);
                    end = cur->child[i];
                }
            }
        }

        string r = "";
        if(!end)    return r;
        while(end->par)  r += end->x, end = end->par;
        reverse(r.begin(), r.end());
        return r;
    }
};