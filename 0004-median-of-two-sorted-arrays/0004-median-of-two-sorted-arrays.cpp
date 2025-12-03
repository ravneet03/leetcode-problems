class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int total = n1 + n2;

        // Positions of median elements in the merged array
        int mid1 = (total - 1) / 2;
        int mid2 = total / 2;

        int i = 0, j = 0, idx = 0;
        int a = 0, b = 0;

        while (idx <= mid2) {
            int val;
            if (i < n1 && (j >= n2 || nums1[i] <= nums2[j])) {
                val = nums1[i++];
            } else {
                val = nums2[j++];
            }

            if (idx == mid1) a = val;
            if (idx == mid2) b = val;
            idx++;
        }

        return (a + b) / 2.0;
    }
};
