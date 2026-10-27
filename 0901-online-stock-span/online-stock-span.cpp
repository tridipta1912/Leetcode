class StockSpanner {
public:
    vector<int> pri;
    stack<int> st;
    StockSpanner() {
        pri.clear();
    }
    
    int next(int price) {
        pri.push_back(price);
        while(!st.empty() && pri[st.top()] <= price)
        {
            st.pop();
        }
        int ans =  pri.size() - (st.empty() ? 0 : st.top() + 1);
        st.push(pri.size() - 1);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */