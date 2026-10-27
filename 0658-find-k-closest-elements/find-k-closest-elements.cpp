class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> sum(n - k + 1);
        sum[0] = 0;
        for (int i = 0; i < k; i++) {
            sum[0] += abs(arr[i] - x);
        }
        for (int i = 1; i <= (n - k); i++) {
            sum[i] = sum[i - 1] + abs(arr[i + k - 1] - x) - abs(arr[i - 1] - x);
        }
        int v = 1e9,ind = 0;
        for (int i = 0; i < sum.size(); i++) 
        {
            if(sum[i]<v)    
            {
                v = sum[i];
                ind = i;
            }
        }

        vector<int> ans(k, 0);
        for (int i = ind; i < (ind + k); i++) {
            ans[i - ind] = arr[i];
        }
        return ans;
    }
};
