class TextEditor {
public:
    list<char> st;
    list<char>::iterator cursor;
    TextEditor() {
        cursor = st.begin();
    }
    
    void addText(string text) {
        st.insert(cursor, text.begin(), text.end());
    }
    
    int deleteText(int k) {
        auto left = cursor;
        int ans = 0;
        for(int i = 1; i <= k && left != st.begin(); i++)
        {
            left--;
            ans++;
        }
        cursor = st.erase(left, cursor);
        return ans;
    }
    
    string cursorLeft(int k) {
        for(int i = 1; i <= k && cursor != st.begin(); i++)
        {
            cursor--;
        }
        string ns = "";
        auto it = cursor;
        for(int i = 0; i < 10 && it != st.begin(); i++) 
        {
            --it;
            ns += *it;
        }
        reverse(ns.begin(), ns.end());
        return ns;
    }
    
    string cursorRight(int k) {
        for(int i = 1; i <= k && cursor != st.end(); i++)
        {
            cursor++;
        }
        auto it = cursor;
        string ns = "";
        for(int i = 0; i < 10 && it != st.begin(); i++) 
        {
            --it;
            ns += *it;
        }
        reverse(ns.begin(), ns.end());
        return ns;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */