class Solution {
  public:
    long long ans = 0;

    void merge(vector<long long> &arr, long long l, long long m, long long r)
    {
        for (long long i = m + 1; i <= r; i++)
        {
            auto it = upper_bound(arr.begin() + l, arr.begin() + m + 1, 2 * arr[i]);
            ans += (arr.begin() + m + 1 - it);
        }

        vector<long long> left(arr.begin() + l, arr.begin() + m + 1);
        vector<long long> right(arr.begin() + m + 1, arr.begin() + r + 1);

        long long ptr1 = 0, ptr2 = 0, k = l;
        while (ptr1 < left.size() && ptr2 < right.size())
        {
            if (left[ptr1] <= right[ptr2]) arr[k++] = left[ptr1++];
            else arr[k++] = right[ptr2++];
        }
        while (ptr1 < left.size()) arr[k++] = left[ptr1++];
        while (ptr2 < right.size()) arr[k++] = right[ptr2++];
    }

    void mergeSort(vector<long long> &arr, long long l, long long r)
    {
        if (l >= r) return;
        long long m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }

    int reversePairs(vector<int> &arr)
    {
        ans = 0;
        vector<long long> arr1(arr.begin(), arr.end());
        mergeSort(arr1, 0, arr.size() - 1); // ✅ fix
        return ans;
    }
};
