**1. Overall Score: 9/10**
This is an excellent, optimal solution that perfectly implements Kadane's Algorithm. It handles the "all negative numbers" edge case correctly because of the order of the `max` operations. The only reason it doesn't get a 10/10 is the use of the magic number `-1e9` for initialization, which can trigger questions in a real interview.

**2. Breakdown (score each /10):**
- **Correctness & edge cases: 10/10** - Handled single-element arrays and arrays with all negative numbers perfectly.
- **Time complexity: 10/10** - $O(N)$ where $N$ is the number of elements in the array. This is the best possible time complexity.
- **Space complexity: 10/10** - $O(1)$ auxiliary space. Only two extra integers (`ans` and `sum`) are used.
- **Code quality: 8/10** - Clean and readable. The initialization of `ans = -1e9` is the only point of contention.
- **Pattern recognition: 10/10** - You perfectly recognized and executed **Kadane's Algorithm** (Dynamic Programming / Greedy).

**3. Missed Edge Cases / Bugs**
There are no functional bugs. The constraints of the problem typically state `nums[i] >= -10^4`, so `-1e9` works fine as a sentinel value here. However, if the array could contain `INT_MIN`, your sentinel would produce an incorrect result.

**4. Would This Pass?**
- **At an OA:** Pass. It is fast, clean, and completely correct for the given constraints.
- **At a live interview:** Pass, but the interviewer will point to `-1e9` and ask, "What if the numbers in the array are extremely small negative numbers? What is a safer way to initialize `ans`?" You just need to answer that you should use `INT_MIN` or `nums[0]`.

**5. Top 3 Improvements**
1. **Remove Magic Numbers:** Always use language-provided limit constants for min/max initialization to make your code bulletproof against constraint changes.
   ```cpp
   #include <climits>
   // ...
   int ans = INT_MIN; // Better
   // OR
   int ans = nums[0]; // Even better, as it relies on actual data
   ```
2. **Type Safety:** `nums.size()` returns a `size_t` (unsigned integer). Comparing a signed `int i` to an unsigned size can cause warnings. Use a range-based for loop for cleaner code that avoids indices entirely:
   ```cpp
   class Solution {
   public:
       int maxSubArray(vector<int>& nums) {
           int ans = nums[0], sum = 0;
           for(int num : nums) {
               sum += num;
               ans = max(ans, sum);
               sum = max(sum, 0);
           }
           return ans;
       }
   };
   ```
3. **Variable Naming:** `sum` is fine, but `current_sum` and `max_sum` (instead of `ans`) explicitly define what the variables are tracking, which helps when explaining the code out loud.

**6. Optimal Solution**
- **Time Complexity:** $O(N)$
- **Space Complexity:** $O(1)$
The optimal solution is exactly what you wrote: Kadane's Algorithm. It maintains a running sum, adding the current element to it. If the running sum becomes negative, it's better to reset it to 0 because any negative prefix sum will only decrease the sum of future subarrays.

**7. What to Practice Next**
Your implementation of Kadane's algorithm is rock solid. To level up this pattern, you should practice variations that require tracking more information or applying Kadane's in 2D. Practice: **"Maximum Product Subarray"** (requires tracking both max and min), **"Maximum Sum Circular Subarray"**, and **"Max Sum of Rectangle No Larger Than K"**.
