class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        while(n)
        {
            pq.push(n % 10);
            n /= 10;
            if(pq.size() > 2)
            {
                pq.pop();
            }
        }

        int ans = pq.top();
        pq.pop();   ans *= pq.top();
        return ans;
    }
};