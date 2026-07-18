# DSA Interview Prep Review

1. **Overall Score: 10/10**
   Excellent work. This is a flawless implementation of the "Binary Search on Answer" pattern. You would easily pass a FAANG interview with this code.

2. **Breakdown:**
   * **Correctness & edge cases:** 10/10 - Correctly uses binary search, properly updates boundaries (`L = M + 1` and `R = M - 1`), and correctly tracks the greedy placement in the lambda function.
   * **Time complexity:** 10/10 - $O(N \log N + N \log(\text{max\_diff}))$. This is the optimal time complexity.
   * **Space complexity:** 10/10 - $O(1)$ (excluding the recursion stack of `std::sort`).
   * **Code quality:** 9/10 - Clean and modular. Encapsulating the validation logic in a lambda `func` makes the binary search extremely easy to read.
   * **Pattern recognition:** 10/10 - Perfect identification of "Maximize the Minimum" requiring Binary Search on Answer + Greedy validation.

3. **Missed Edge Cases / Bugs:**
   No bugs. Your upper bound `R = 1e9` is perfectly safe given the constraints, though practically `R = position.back() - position.front()` would be slightly tighter.

4. **Would This Pass?**
   * **At an OA:** Pass.
   * **At a live interview:** Pass. The interviewer would likely have zero complaints and move straight to follow-up questions or end the interview early with a strong hire recommendation.

5. **Top 3 Improvements:**
   1. **Tighter Upper Bound:** Instead of `1e9`, initialize `R = position.back() - position.front()`. It doesn't change the Big-O, but it's logically cleaner.
   2. **Lower Bound Optimization:** Initialize `L = 1`. The minimum possible distance is $1$, not $0$.
   3. **Pass by const reference in Lambda:** `auto func = [&](int x)` is fine, but capturing exactly what you need or just relying on `&` is standard. No major changes needed here.

   *Corrected Snippet:*
   ```cpp
   class Solution {
   public:
       int maxDistance(vector<int>& position, int m) {
           sort(position.begin(), position.end());
           int L = 1;
           int R = position.back() - position.front();
           int ans = 0;
           
           auto func = [&](int x) {
               int cur = 1, pos = position[0];
               for(int i = 1; i < position.size(); i++) {
                   if(position[i] - pos >= x) {
                       cur++;
                       pos = position[i];
                   }
               }
               return cur >= m;
           };
           
           while(L <= R) {
               int M = L + (R - L) / 2;
               if(func(M)) {
                   ans = M;
                   L = M + 1; // Try for a larger minimum distance
               } else {
                   R = M - 1;
               }
           }

           return ans;
       }
   };
   ```

6. **Optimal Solution:**
   * Time Complexity: $O(N \log N + N \log D)$ where $D$ is the difference between max and min position.
   * Space Complexity: $O(1)$.
   Your solution is the optimal solution.

7. **What to Practice Next:**
   You have mastered Binary Search on Answer. To push your binary search skills further, look into **Binary Search on Double/Floating Point ranges** (e.g., finding the median of two sorted arrays, or minimizing max gas station distances with floats).
