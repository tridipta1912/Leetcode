class Solution {
public:
    int findIndex(const vector<int>& vec, int target) 
    {
    auto it = find(vec.begin(), vec.end(), target);

    if (it != vec.end()) {
        return distance(vec.begin(), it);  // Return index if element is found
    } else {
        return -1;  // Return -1 if element is not found
    }
}
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> n(nums2.size(), 0);
        vector<int> ans;

        for (int i = 0; i < nums2.size(); i++) {
            while (!s.empty() && nums2[i] > nums2[s.top()]) {
                n[s.top()] = nums2[i];
                s.pop();
            }
            s.push(i); // Push the current index onto the stack
        }

        while (!s.empty()) {
            n[s.top()] = -1;
            s.pop();
        }

        for (int i = 0; i < nums1.size(); i++) 
        {
            int ind = findIndex(nums2, nums1[i]);
            ans.push_back(n[ind]);
        }
        return ans;
    }
};