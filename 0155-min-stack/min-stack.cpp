class MinStack {
public:
    using ll = long long;
    stack<ll> st, minn;
    MinStack() {
    }
    
    void push(int value) {
        st.push(value);
        if(minn.empty() || minn.top() >= value)  minn.push(value);
    }
    
    void pop() {
        if(minn.top() == st.top())  minn.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minn.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */