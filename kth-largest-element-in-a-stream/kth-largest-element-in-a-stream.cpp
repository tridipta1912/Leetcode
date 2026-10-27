class KthLargest {
public:
    int m_k;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) : m_k{k} {
        for(auto x : nums)  
        {
            if(pq.size() < k) pq.push(x);
            else if(pq.top() < x)   pq.pop(), pq.push(x);
        }
    }
    
    int add(int x) {
        if(pq.size() < m_k) pq.push(x);
        else if(pq.top() < x)   pq.pop(), pq.push(x);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */