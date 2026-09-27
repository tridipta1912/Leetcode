struct Node 
{
    bool is_end = false;
    Node* child[26];
    Node()
    {
        is_end = false;
        fill(begin(child), end(child), nullptr);
    }
};
class WordDictionary {
public:
    Node *root {nullptr};
    WordDictionary() : root{new Node()}{
        
    }
    
    void addWord(string word) {
        Node *cur = root;
        for(auto x : word)
        {
            if(!cur->child[x - 'a'])    cur->child[x - 'a'] = new Node();
            cur = cur->child[x - 'a'];
        }
        cur->is_end = true;
    }
    
    bool search(string word) {
    
        auto dfs = [&](this auto &self, Node *cur, int idx) -> bool
        {
            bool x = false;
            if(!cur)    return false;
            if(idx == word.size())    return (cur->is_end);
            if(word[idx] != '.')    return (self(cur->child[word[idx] - 'a'], idx + 1));
            for(int i = 0; i < 26; i++)
            {
                x |= self(cur->child[i], idx + 1);
            }
            return x;
        };
        return dfs(root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */