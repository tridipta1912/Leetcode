class Solution {
public:
    int totalWaviness(int num1, int num2) {
        auto find = [&](int x)
        {
            vector<int> a;
            while(x)
            {
                a.push_back(x % 10);
                x /= 10;
            }  
            int ans = 0;
            for(int i = 1; i + 1 < a.size(); i++)
            {
                ans += (a[i] > max(a[i + 1], a[i - 1]));
                ans += (a[i] < min(a[i + 1], a[i - 1]));
            }
            return ans;
        };

        int ans = 0;
        for(int i = num1; i <= num2; i++) ans += find(i);
        return ans;
    }
};