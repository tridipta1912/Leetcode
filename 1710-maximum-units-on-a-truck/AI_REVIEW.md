# DSA Interview Prep Review

1. **Overall Score: 9/10**
   This is a solid passing solution. You recognized the "Fractional Knapsack"-style greedy pattern (without the fractions) and correctly sorted by the highest value-to-weight ratio.

2. **Breakdown:**
   * **Correctness & edge cases:** 10/10 - Correctly handles constraints and takes the minimum of remaining truck size or available boxes.
   * **Time complexity:** 10/10 - $O(N \log N)$ where $N$ is the number of box types, dominated by the sort.
   * **Space complexity:** 9/10 - $O(1)$ or $O(\log N)$ depending on the `std::sort` implementation. This is optimal.
   * **Code quality:** 8/10 - Very readable. Capturing variables in the lambda is unnecessary since it doesn't use outside variables. Also, passing vectors by value in the lambda `(vector<int> a, vector<int> b)` causes unnecessary copying, which slows down the sort.
   * **Pattern recognition:** 10/10 - Perfect execution of the Greedy pattern.

3. **Missed Edge Cases / Bugs:**
   No logical bugs.

4. **Would This Pass?**
   * **At an OA:** Pass. $O(N \log N)$ easily clears the $1000$ length constraint.
   * **At a live interview:** Pass. The interviewer would point out the pass-by-value in your lambda and ask you to fix it. If the constraints on `numberOfUnitsPerBox` were small (e.g., up to $1000$), they might also ask if you can sort it in $O(N)$ time using Bucket Sort/Counting Sort.

5. **Top 3 Improvements:**
   1. **Pass by const reference in Lambda:** `[&](const vector<int>& a, const vector<int>& b)` avoids copying the vectors on every comparison during the sort.
   2. **Bucket Sort Optimization:** Since `numberOfUnitsPerBox` is constrained to $1000$, you can achieve $O(N + 1000)$ time using a bucket sort array instead of $O(N \log N)$ standard sort.
   3. **Early Exit:** If `truckSize` hits $0$, you can `break` out of the loop early instead of checking `min(boxes, 0)`.

   *Corrected Snippet (Fixing the Lambda & Adding Early Exit):*
   ```cpp
   class Solution {
   public:
       int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
           int ans = 0;
           // Pass by const reference!
           sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
               return a[1] > b[1];
           });
           
           for(const auto& box : boxTypes) {
               if (truckSize == 0) break;
               int take = min(box[0], truckSize);
               ans += take * box[1];
               truckSize -= take;
           }
           return ans;
       }
   };
   ```

6. **Optimal Solution:**
   * Time Complexity: $O(N \log N)$ (or $O(N + K)$ with Bucket Sort).
   * Space Complexity: $O(1)$ auxiliary.
   Your greedy choice is optimal. The bucket sort variation is technically faster but standard sort is completely acceptable and usually expected.

7. **What to Practice Next:**
   You have Greedy down. Practice **Bucket Sort/Counting Sort** applications. Recognize when constraints (like $nums[i] \le 1000$) allow you to bypass $O(N \log N)$ sorting.
