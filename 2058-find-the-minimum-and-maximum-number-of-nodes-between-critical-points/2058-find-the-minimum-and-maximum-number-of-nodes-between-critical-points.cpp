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
        int min1 = -1, max1 = -1, lst = -1, minn = 1e9;
        while(tmp)
        {
            st.push_back(tmp->val);
            cur++;
            if(st.size() == 3)
            {
                bool b = false;
                if(min(st[0], st[2]) > st[1])   b = true;
                if(max(st[0], st[2]) < st[1])   b = true;
                st.pop_front();

                if(b)
                {
                    if(min1 == -1)   min1 = cur;
                    max1 = cur;
                    if(lst != -1)   minn = min(minn, cur - lst);
                    lst = cur;
                }
            }
            tmp = tmp->next;
        }

        vector<int> ans = {-1, -1};

        if(min1 == max1)  return ans;

        ans = {minn, max1 - min1};

        return ans;
    }
};