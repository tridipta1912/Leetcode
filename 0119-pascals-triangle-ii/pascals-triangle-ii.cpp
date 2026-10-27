class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> old = {1};
        for(int j = 1; j <= rowIndex; j++)
        {
            vector<int> ne(old.size() + 1);
            ne.front() = 1;
            ne.back() = 1;
            for(int i = 1; i < old.size(); i++)
            {
                ne[i] = old[i] + old[i - 1];
            }
            swap(old, ne);
        }
        return old;
    }
};