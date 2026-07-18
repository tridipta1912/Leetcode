class MedianFinder {
public:
    priority_queue<int> maxx;
    priority_queue<int, vector<int>, greater<int>> minn;

    MedianFinder() {

    }
    
    void addNum(int num) {
        maxx.push(num);
        if(maxx.size() - minn.size() > 1)   
        {
            minn.push(maxx.top());
            maxx.pop();
        }
        while(!minn.empty() && maxx.top() > minn.top())
        {
            int A = maxx.top();  maxx.pop();
            int B = minn.top(); minn.pop();
            maxx.push(B);   minn.push(A);
        }
    }
    
    double findMedian() {
        if(maxx.size() == minn.size())     return double(maxx.top() + minn.top()) / 2.0;
        return (double)maxx.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */