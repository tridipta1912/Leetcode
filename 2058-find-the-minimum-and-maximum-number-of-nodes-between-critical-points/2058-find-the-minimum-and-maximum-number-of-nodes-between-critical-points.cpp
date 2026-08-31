/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> loc;
        ListNode* tmp = head;
        deque<int> st;
        int cur = 0;
        while(tmp)
        {
            st.push_back(tmp->val);
            cur++;
            if(st.size() == 3)
            {
                if(min(st[0], st[2]) > st[1])   loc.push_back(cur);
                if(max(st[0], st[2]) < st[1])   loc.push_back(cur);
                st.pop_front();
            }
            tmp = tmp->next;
        }

        vector<int> ans = {-1, -1};
        if(loc.size() < 2)  return ans;
        ans[0] = 1e9;
        for(int i = 0; i + 1 < loc.size(); i++)   ans[0] = min(ans[0], loc[i + 1] - loc[i]);
        ans[1] = loc.back() - loc.front();
        return ans;
    }
};