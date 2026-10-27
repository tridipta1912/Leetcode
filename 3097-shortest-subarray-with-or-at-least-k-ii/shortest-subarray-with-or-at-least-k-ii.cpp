class Solution {
public:
    int recalculateOr(const vector<int>& bits) {
        int x = 0;
        for (int j = 0; j < 32; j++) {
            if (bits[j] > 0) x |= (1 << j);
        }
        return x;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bits(32, 0); // Tracks count of bits set at each position
        deque<int> dq;
        int ans = 1e9;
        int orr = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Add current number to deque and update bit counts
            dq.push_back(nums[i]);
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j)) bits[j]++;
            }
            orr |= nums[i];

            // Check and remove elements from the front while maintaining conditions
            while (!dq.empty() && orr >= k) {
                ans = min(ans, (int)dq.size()); // Update answer
                int to_remove = dq.front();
                dq.pop_front();
                for (int j = 0; j < 32; j++) {
                    if (to_remove & (1 << j)) bits[j]--;
                }
                orr = recalculateOr(bits); // Recalculate OR
            }
        }

        return (ans == 1e9) ? -1 : ans; // Return -1 if no valid subarray found
    }
};
