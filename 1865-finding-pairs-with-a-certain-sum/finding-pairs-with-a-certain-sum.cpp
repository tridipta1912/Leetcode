class FindSumPairs {
public:
    map<int, int> mp1, mp2;
    vector<int> nums;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto c : nums1) mp1[c]++;
        for(auto c : nums2) mp2[c]++;
        nums = nums2;
    }
    
    void add(int index, int val) {
        mp2[nums[index]]--;
        nums[index] += val;
        mp2[nums[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto [a, b] : mp1)  if(mp2.count(tot - a))  ans += (b * mp2[tot - a]);
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */