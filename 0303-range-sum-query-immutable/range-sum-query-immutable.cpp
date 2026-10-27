class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr.resize(nums.size());
        for(int i = 0; i < nums.size(); i++)    arr[i] = nums[i] + ((i > 0) ? arr[i - 1] : 0);
    }
    
    const int sumRange(int left, int right) {
        return (arr[right] - ((left == 0) ? 0 : arr[left - 1]));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */