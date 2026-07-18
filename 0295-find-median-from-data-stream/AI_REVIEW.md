**1. Overall Score: 8/10**
You successfully identified and implemented the optimal **Two Heaps** pattern for this classic Hard problem. Your time and space complexities are exactly what is expected. However, your rebalancing logic inside `addNum` is slightly convoluted and does more manual swapping than necessary, which makes the code harder to read and prone to bugs during a live interview.

**2. Breakdown (score each /10):**
- **Correctness & edge cases: 10/10** - Correctly tracks the median for both even and odd length streams. 
- **Time complexity: 10/10** - $O(\log N)$ for `addNum` and $O(1)$ for `findMedian`. This is optimal for this pattern.
- **Space complexity: 10/10** - $O(N)$ to store the data stream in the two heaps.
- **Code quality: 6/10** - Your `addNum` logic manually checks size differences and then runs a `while` loop to swap elements between the heaps if the max-heap has a larger element than the min-heap. This is not the standard way to balance these heaps and introduces unnecessary cognitive load.
- **Pattern recognition: 10/10** - You perfectly recognized the **Two Heaps** (Max-Heap for the lower half, Min-Heap for the upper half) pattern.

**3. Missed Edge Cases / Bugs**
There are no logic bugs. However, be extremely careful with `maxx.size() - minn.size() > 1`. `size()` returns an unsigned integer (`size_t`). If `minn` somehow became larger than `maxx`, this subtraction would underflow to a massive positive number, bypassing your `if` condition. Since you always push to `maxx` first, it happens to be safe here, but it's a dangerous C++ habit.

**4. Would This Pass?**
- **At an OA:** Pass.
- **At a live interview:** Pass, but the interviewer will ask you to simplify the `addNum` logic. They want to see if you understand how to unconditionally transfer the largest element from the lower half to the upper half.

**5. Top 3 Improvements**
1. **Simplify Rebalancing Logic:** You do not need a `while` loop or manual swaps. The standard trick is to *always* push the new number to the max-heap, then immediately pop the top of the max-heap and push it to the min-heap. This guarantees the min-heap only gets the largest numbers. Finally, fix the sizes if the min-heap grew too large.
   ```cpp
   class MedianFinder {
       priority_queue<int> max_heap; // Lower half
       priority_queue<int, vector<int>, greater<int>> min_heap; // Upper half
   public:
       void addNum(int num) {
           max_heap.push(num);
           min_heap.push(max_heap.top());
           max_heap.pop();
           
           // Maintain size property: max_heap can have at most 1 more element than min_heap
           if (max_heap.size() < min_heap.size()) {
               max_heap.push(min_heap.top());
               min_heap.pop();
           }
       }
       
       double findMedian() {
           if (max_heap.size() > min_heap.size()) {
               return max_heap.top();
           }
           return (max_heap.top() + min_heap.top()) / 2.0;
       }
   };
   ```
2. **Use `size_t` Casts or Int Casts:** If you ever do math with `.size()`, cast it to `int` first to prevent unsigned integer underflow bugs: `(int)maxx.size() - (int)minn.size() > 1`.
3. **Avoid Division by Integer Literal:** `double(maxx.top() + minn.top()) / 2.0` is correct, but `(maxx.top() + minn.top()) / 2.0` automatically promotes the numerator to double because of `2.0`. It's minor, but cleaner.

**6. Optimal Solution**
- **Time Complexity:** $O(\log N)$ for `addNum`, $O(1)$ for `findMedian`.
- **Space Complexity:** $O(N)$
The optimal solution is the **Two Heaps** pattern. A Max-Heap stores the smaller half of the numbers, and a Min-Heap stores the larger half. The heaps are balanced such that the Max-Heap either has the same number of elements as the Min-Heap or exactly one more.

**7. What to Practice Next**
Your pattern recognition is great. Practice similar stream/interval problems that require multiple data structures to maintain a moving invariant. Practice: **"Sliding Window Median"** and **"IPO"** (which also uses a two-heap greedy approach).
