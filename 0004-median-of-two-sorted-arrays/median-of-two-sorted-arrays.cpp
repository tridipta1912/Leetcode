class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> nums;
      for(int i = 0; i<nums1.size();i++)
      {
          nums.push_back(nums1[i]);
      }
      for(int i = 0;i<nums2.size();i++)
      {
          nums.push_back(nums2[i]);
      }
      sort(nums.begin(),nums.end());
      double med;
      int i = nums.size();
      if(i%2!=0) 
      {
          double k = nums[i/2];
          return k;
      }  
      if(i%2==0)
      {
          double k;
          k = 0.5*(nums[i/2]+nums[(i/2)-1]);
          return k;
      }
      return 0;
    }
};