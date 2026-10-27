class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        for (auto v : basket1) freq[v]++;
        for (auto v : basket2) freq[v]++;
        
        for (auto& [num, f] : freq) 
        {
            if (f % 2) return -1; 
            f /= 2; 
        }

        unordered_map<int, int> copy = freq;
        vector<int> extra1, extra2;

        for (auto v : basket1) 
        {
            if (freq[v] > 0) 
            {
                freq[v]--;
            } 
            else 
            {
                extra1.push_back(v);
            }
        }

        freq = copy;
        for (auto v : basket2) 
        {
            if (freq[v] > 0) 
            {
                freq[v]--;
            } 
            else 
            {
                extra2.push_back(v);
            }
        }

        sort(extra1.begin(), extra1.end());
        sort(extra2.begin(), extra2.end(), greater<int>());

        int n = extra1.size(); 
        int minn = min(*min_element(basket1.begin(), basket1.end()),
                          *min_element(basket2.begin(), basket2.end()));

        long long cost = 0;
        for (int i = 0; i < n; i++) {
            int a = extra1[i];
            int b = extra2[i];
            cost += min(2 * minn, min(a, b));
        }

        return cost;
    }
};
