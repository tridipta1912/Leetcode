class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> arr;
        auto find = [&](int x)
        {
            for(auto y : arr)  if(x == y)  return false;
            return true;
        };
        for(auto x : nums)
        {
            if(find(x))
            {
                arr.push_back(x);
                sort(arr.begin(), arr.end(), greater<int>());
                if(arr.size() > 3)
                {
                    arr.pop_back();
                }
            }
        }
        for(auto x : arr)   cout << x << ' ';
        if(arr.size() < 3)  return arr[0];
        return arr[2];
    }
};