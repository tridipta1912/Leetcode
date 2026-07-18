# DSA Interview Prep Review

1. **Overall Score: 10/10**
   This is a math brainteaser, and you saw straight through it. Excellent job recognizing the mathematical reduction instead of simulating the sums.

2. **Breakdown:**
   * **Correctness & edge cases:** 10/10 - Correct for all $N$.
   * **Time complexity:** 10/10 - $O(1)$. Optimal.
   * **Space complexity:** 10/10 - $O(1)$. Optimal.
   * **Code quality:** 10/10 - Can't get any cleaner than `return n;`.
   * **Pattern recognition:** 10/10 - You correctly identified that:
     1. Sum of first $n$ odd numbers = $n^2$
     2. Sum of first $n$ even numbers = $n(n+1)$
     3. $\text{GCD}(n^2, n(n+1)) = n \times \text{GCD}(n, n+1) = n \times 1 = n$.

3. **Missed Edge Cases / Bugs:**
   None.

4. **Would This Pass?**
   * **At an OA:** Pass.
   * **At a live interview:** Pass. The interviewer would ask you to write out the mathematical proof for why the answer is always $n$. As long as you can explain the three points listed above, you pass easily.

5. **Top 3 Improvements:**
   None. The solution is perfect.

   *Corrected Snippet:*
   ```cpp
   class Solution {
   public:
       int gcdOfOddEvenSums(int n) {
           // Sum of n odds = n^2
           // Sum of n evens = n(n+1)
           // GCD(n^2, n(n+1)) = n * GCD(n, n+1) = n * 1 = n
           return n;
       }
   };
   ```

6. **Optimal Solution:**
   * Time Complexity: $O(1)$
   * Space Complexity: $O(1)$
   This is the optimal solution.

7. **What to Practice Next:**
   You clearly have a strong grasp of number theory and sequence sums. Continue practicing **Math & Brainteaser** problems on LeetCode to keep this pattern recognition sharp.
