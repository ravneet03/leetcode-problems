class Solution {
public:
    int searchHelper(vector<int>& nums, int s, int e, int k) {
        if (s > e) 
            return -1; 

        int mid = s + (e - s) / 2;

        if (nums[mid] == k)
            return mid;
        else if (nums[mid] < k)
            return searchHelper(nums, mid + 1, e, k);
        else
            return searchHelper(nums, s, mid - 1, k);
    }

    int search(vector<int>& nums, int k) {
        return searchHelper(nums, 0, nums.size() - 1, k);
    }
};
