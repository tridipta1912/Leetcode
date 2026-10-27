class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        stack<int> s;
        int x = temperatures.size();
        vector<int> ans(x, 0);  // Initialize ans with the same size as temperatures and set all elements to 0

        for(int i = 0; i < x; i++)
        {
            while(!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }

        while(!s.empty())
        {
            ans[s.top()] = 0;
            s.pop();
        }

        return ans;
    }
};