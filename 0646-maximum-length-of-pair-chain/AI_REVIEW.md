# DSA Interview Prep Review

1. **Overall Score: 9/10**
   This would easily pass an interview. You correctly identified the optimal greedy approach (interval scheduling) over the slower dynamic programming approach. Sorting by the end time is the textbook way to solve this.

2. **Breakdown:**
   * **Correctness & edge cases:** 10/10 - Correctly handles negative numbers and all constraints given. 
   * **Time complexity:** 10/10 - $O(N \log N)$ due to sorting. This is the most optimal approach.
   * **Space complexity:** 9/10 - $O(1)$ space (or $O(\log N)$ depending on the internal sorting algorithm used by C++ `std::sort`). 
   * **Code quality:** 8/10 - Very readable. `maxx` is slightly confusing as a name (it acts as `current_end`). 
   * **Pattern recognition:** 10/10 - You perfectly recognized the "Interval Scheduling Maximization" greedy pattern. Many candidates fall into the trap of using $O(N^2)$ LIS (Longest Increasing Subsequence) DP here.

3. **Missed Edge Cases / Bugs:**
   No bugs. The initialization of `maxx = -1001` is perfectly safe because the problem constraints state that elements are at least `-1000`.

4. **Would This Pass?**
   * **At an OA:** Pass. Easily clears time limits.
   * **At a live interview:** Pass. The interviewer would ask you to prove why sorting by the *second* element is optimal compared to sorting by the first. Be ready to explain the greedy choice property (picking the interval that ends earliest leaves the most room for future intervals).

5. **Top 3 Improvements:**
   1. **Variable naming:** Rename `maxx` to `current_end` or `last_end`. `maxx` implies a maximum value rather than a boundary.
   2. **Sorting lambda:** Pass by `const vector<int>&` in the lambda function to avoid unnecessary copies (though since you used `&`, it's just a reference, but adding `const` is better practice).
   3. **Magic numbers:** Instead of `-1001`, using a standard constant like `INT_MIN` is safer and more idiomatic.

   *Corrected Snippet:*
   ```cpp
   class Solution {
   public:
       int findLongestChain(vector<vector<int>>& pairs) {
           sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
               return a[1] < b[1];
           });

           int ans = 0, current_end = INT_MIN;

           for(const auto& x : pairs) {
               if(x[0] > current_end) {
                   current_end = x[1];
                   ans++;
               }
           }

           return ans;
       }
   };
   ```

6. **Optimal Solution:**
   * Time Complexity: $O(N \log N)$ for sorting.
   * Space Complexity: $O(1)$ auxiliary space.
   Your greedy approach is the optimal solution.

7. **What to Practice Next:**
   You have a solid grasp on interval-based greedy problems. To push yourself, practice Sweep Line algorithms (e.g., "Meeting Rooms II", "My Calendar I/II/III").
