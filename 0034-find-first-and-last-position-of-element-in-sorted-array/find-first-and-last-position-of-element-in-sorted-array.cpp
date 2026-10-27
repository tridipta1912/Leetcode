class Solution {
public:
    int upper_bound(int k, vector<int> a) {
        int last = -1;
        int L = 0;
        int R = a.size() - 1;
        int M;
        int target = k;
        while (L <= R) {
            M = L + (R - L)/2;
            if (a[M] <= target)
                L = M + 1;
            else if (a[M] > target)
                R = M - 1;
        }
        return (R);
    }

    int lower_bound(int k, vector<int> a) {
        int L = 0;
        int R = a.size() - 1;
        int M;
        while (L <= R) {
            M = L + (R - L) / 2;
            if (a[M] < k)
                L = M + 1;
            else if (a[M] >= k)
                R = M - 1;
        }
        return (L);
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if(nums.size()==0)  return {-1,-1};

        int f = lower_bound(target, nums);
        int l = upper_bound(target, nums);

        if(f<0 || f>=nums.size()) f = -1; 
        else if(nums[f]!=target)    f = -1;

        if(l<0 || l>=nums.size()) l = -1;
        else    if(nums[l]!=target)    l = -1;

        return {f,l};
    }
};