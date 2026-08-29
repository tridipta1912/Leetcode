class MyQueue {
public:
    using ll = int;
    stack<ll> st, qu;
    MyQueue() {
        
    }
    
    void push(int x) {
        qu.push(x);
    }
    
    int pop() {
        if(st.empty())
        {
            while(!qu.empty())
            {
                st.push(qu.top());
                qu.pop();
            }
        }
        ll x = st.top();
        st.pop();
        return x;
    }
    
    int peek() {
        if(st.empty())
        {
            while(!qu.empty())
            {
                st.push(qu.top());
                qu.pop();
            }
        }
        ll x = st.top();
        return x;
    }
    
    bool empty() {
    return st.empty() && qu.empty();
}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */