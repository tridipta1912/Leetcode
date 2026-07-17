<h2><a href="https://leetcode.com/problems/copy-list-with-random-pointer">138. Copy List with Random Pointer</a></h2><h3>Medium</h3><hr><p>A linked list of length <code>n</code> is given such that each node contains an additional random pointer, which could point to any node in the list, or <code>null</code>.</p>

<p>Construct a <a href="https://en.wikipedia.org/wiki/Object_copying#Deep_copy" target="_blank"><strong>deep copy</strong></a> of the list. The deep copy should consist of exactly <code>n</code> <strong>brand new</strong> nodes, where each new node has its value set to the value of its corresponding original node. Both the <code>next</code> and <code>random</code> pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. <strong>None of the pointers in the new list should point to nodes in the original list</strong>.</p>

<p>For example, if there are two nodes <code>X</code> and <code>Y</code> in the original list, where <code>X.random --&gt; Y</code>, then for the corresponding two nodes <code>x</code> and <code>y</code> in the copied list, <code>x.random --&gt; y</code>.</p>

<p>Return <em>the head of the copied linked list</em>.</p>

<p>The linked list is represented in the input/output as a list of <code>n</code> nodes. Each node is represented as a pair of <code>[val, random_index]</code> where:</p>

<ul>
	<li><code>val</code>: an integer representing <code>Node.val</code></li>
	<li><code>random_index</code>: the index of the node (range from <code>0</code> to <code>n-1</code>) that the <code>random</code> pointer points to, or <code>null</code> if it does not point to any node.</li>
</ul>

<p>Your code will <strong>only</strong> be given the <code>head</code> of the original linked list.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/e1.png" style="width: 700px; height: 142px;" />
<pre>
<strong>Input:</strong> head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
<strong>Output:</strong> [[7,null],[13,0],[11,4],[10,2],[1,0]]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/e2.png" style="width: 700px; height: 114px;" />
<pre>
<strong>Input:</strong> head = [[1,1],[2,1]]
<strong>Output:</strong> [[1,1],[2,1]]
</pre>

<p><strong class="example">Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/e3.png" style="width: 700px; height: 122px;" /></strong></p>

<pre>
<strong>Input:</strong> head = [[3,null],[3,0],[3,null]]
<strong>Output:</strong> [[3,null],[3,0],[3,null]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 1000</code></li>
	<li><code>-10<sup>4</sup> &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li><code>Node.random</code> is <code>null</code> or is pointing to some node in the linked list.</li>
</ul>

---
### AI Code Review

1. **Overall Score: 7/10**
This would likely pass an OA, but in a live interview, the interviewer would immediately point out that using `std::map` introduces an unnecessary `O(N log N)` time complexity. They would expect you to at least use an `unordered_map` for `O(N)` time, and push you towards the `O(1)` space interleaving technique.

2. **Breakdown (score each /10):**
- **Correctness & edge cases: 10/10** - The code correctly handles edge cases like empty inputs (since `while(cur)` safely ignores `null` heads, and `hash[head]` returns `null`).
- **Time complexity: 4/10** - **O(N log N)**. You used `std::map`, which is a red-black tree in C++. Lookup/insertion takes `O(log N)`. This does not match the expected optimal `O(N)` time.
- **Space complexity: 7/10** - **O(N)**. An extra `map` is used to store the node mappings. While standard, there is a known `O(1)` space optimization for this specific problem.
- **Code quality: 8/10** - Clean and readable. Variable names (`cur`, `ncur`) are decent, but could be slightly more descriptive (e.g., `curr`, `newNode`).
- **Pattern recognition: 7/10** - You recognized the hash map pattern for deep copies, which is good, but you used the wrong underlying C++ data structure (`map` vs `unordered_map`) and missed the interleaving pattern.

3. **Missed Edge Cases / Bugs**
No functional bugs. The logic is robust and will pass all LeetCode test cases. It correctly handles `null` values for `next` and `random` because `hash[NULL]` automatically inserts a key-value pair of `NULL: NULL` in C++ maps, which gracefully returns `NULL`.

4. **Would This Pass?**
- **At an OA (auto-graded, all test cases):** Pass. The bounds on this problem are small enough (usually N <= 1000) that `O(N log N)` won't TLE.
- **At a live interview:** The interviewer would ask "Can we improve the time complexity?" (expecting `unordered_map`) and then "Can we do this without extra space?" (expecting the interleaving algorithm).

5. **Top 3 Improvements**
- **Use `unordered_map` instead of `map`:** This immediately drops your time complexity from `O(N log N)` to `O(N)`.
- **Remove extra space with Interleaving:** Weave the original and copied nodes together.
- **Be careful with implicit map insertions:** `hash[NULL]` inserts a new element. While harmless here, it's a dangerous habit.

Corrected code snippet (using `unordered_map`):
```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> hash;
        
        Node* cur = head;
        while (cur) {
            hash[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur) {
            hash[cur]->next = hash[cur->next];
            hash[cur]->random = hash[cur->random];
            cur = cur->next;
        }

        return hash[head];
    }
};
```

6. **Optimal Solution**
**Time: O(N), Space: O(1)** (excluding the space for the new list).
*Interleaving Approach:*
1. Iterate through the list and create a copy of each node, inserting it right next to the original node (e.g., A -> A' -> B -> B').
2. Iterate again and set the random pointers for the copied nodes: `cur->next->random = cur->random ? cur->random->next : nullptr`.
3. Iterate a third time to detach the copied nodes into their own separate list and restore the original list.

7. **What to Practice Next**
You should drill **Linked List Manipulation** problems, specifically ones that require structural modifications in place (like reversing sublists, interleaving, or cycle detection). Practice being extremely careful with pointers and avoiding extra `O(N)` space when the problem can be solved in-place.
