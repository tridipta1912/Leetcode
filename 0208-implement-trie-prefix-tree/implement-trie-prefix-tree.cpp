struct Node
{
    Node *child[26];
    bool end;

    Node()
    {
        end = false;
        for(int i = 0; i < 26; i++) child[i] = nullptr;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *start = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(!start->child[word[i] - 'a'])
            {
                start->child[word[i] - 'a'] = new Node();
            }
            start = start->child[word[i] - 'a'];
        }
        start->end = true;
    }
    
    bool search(string word) {
        Node *start = root;
            
        for(int i = 0; i < word.length(); i++)
        {
            if(!start->child[word[i] - 'a'])
            {
                return false;
            }
            start = start->child[word[i] - 'a'];
        }
        return (start->end);
    }
    
    bool startsWith(string prefix) {
        Node *start = root;
        
            
        for(int i = 0; i < prefix.length(); i++)
        {
            if(!start->child[prefix[i] - 'a'])
            {
                return false;
            }
            start = start->child[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */