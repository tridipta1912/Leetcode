# DSA Interview Prep Review

1. **Overall Score: 10/10**
   Brilliant solution. You recognized that the core of this problem reduces to finding the "Maximum Subarray Sum" of the differences between the two arrays, and you applied Kadane's Algorithm perfectly. This is exactly what top companies look for in Hard problems.

2. **Breakdown:**
   * **Correctness & edge cases:** 10/10 - Properly calculates the maximum possible gain from swapping a subarray. Correctly handles the case where no swap is better (since `maxx` is initialized to $0$, representing an empty swap).
   * **Time complexity:** 10/10 - $O(N)$. Calculates the sum and difference array logic in a single linear pass per array.
   * **Space complexity:** 10/10 - $O(1)$. You didn't allocate a new array for the differences; you calculated it on the fly.
   * **Code quality:** 9/10 - Modular logic via the lambda `find` avoids duplicating the Kadane's loop twice. 
   * **Pattern recognition:** 10/10 - Translating "maximize the sum of an array after swapping a subarray" into "apply Kadane's algorithm to the delta array" is a high-level algorithmic leap. Perfect pattern recognition.

3. **Missed Edge Cases / Bugs:**
   No bugs. `sum = max(sum, 0)` perfectly resets the running Kadane's sum when the delta becomes negative.

4. **Would This Pass?**
   * **At an OA:** Pass. $O(N)$ effortlessly handles $N = 10^5$.
   * **At a live interview:** Strong Hire. The interviewer would love the use of the lambda to DRY (Don't Repeat Yourself) the code. 

5. **Top 3 Improvements:**
   1. **Pass vectors by const reference to Lambda:** You passed `vector<int> &n1, vector<int> &n2` without `const`. Since you don't modify them, `const vector<int>&` is safer and better practice.
   2. **Variable initialization:** The loop `for(int i = 0; i < nums1.size(); i++)` uses `nums1.size()`, but since the lambda acts generally on `n1` and `n2`, it should technically use `n1.size()` for safety, even though the problem guarantees they are the same length.
   3. **No logic changes needed.**

   *Corrected Snippet:*
   ```cpp
   class Solution {
   public:
       int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
           auto find = [&](const vector<int>& n1, const vector<int>& n2) {
               int base_sum = 0;
               for(int x : n1) base_sum += x;
               
               int max_gain = 0, current_gain = 0;
               for(int i = 0; i < n1.size(); i++) {
                   current_gain += (n2[i] - n1[i]);
                   max_gain = max(max_gain, current_gain);
                   current_gain = max(current_gain, 0); // Kadane's reset
               }
               return base_sum + max_gain;
           };
           
           return max(find(nums1, nums2), find(nums2, nums1));
       }
   };
   ```

6. **Optimal Solution:**
   * Time Complexity: $O(N)$
   * Space Complexity: $O(1)$
   Your implementation using Kadane's algorithm on the fly is the mathematically optimal solution.

7. **What to Practice Next:**
   You have excellent command of array reduction and Kadane's. Move on to **Prefix Sums + Hash Maps** (like "Subarray Sum Equals K" variations) or **Sliding Window Maximum** to ensure your subarray skills are rounded out across all patterns.
