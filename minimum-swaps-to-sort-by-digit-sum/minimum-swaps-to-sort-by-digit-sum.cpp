class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> nums1(nums.begin(), nums.end());
        auto dig = [&](int x)
        {
            int sum = 0;
            while(x)
            {
                sum += (x % 10);
                x /= 10;
            }
            return sum;
        };

        sort(nums1.begin(), nums1.end(), [&](int x, int y)
        {
            int cx = dig(x), cy = dig(y);
            if(cx == cy)    return (x < y);
            return (cx < cy);
        });
        
        int n = nums.size();
        int ans = n;
        unordered_map<int, int> pos;
        for(int i = 0; i < n; i++)  pos[nums1[i]] = i;
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++)
        {
            int u = i, v = pos[nums[i]];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n);
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                ans--;
                queue<int> q;
                q.push(i);
                vis[i] = true;
                while(!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    for(auto v : adj[u])    if(!vis[v]) vis[v] = 1, q.push(v);
                }
            }
        }
        return ans;
    }
};