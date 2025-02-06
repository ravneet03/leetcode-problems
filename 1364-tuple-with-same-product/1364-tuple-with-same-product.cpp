class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        vector<int> productPairs;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                productPairs.push_back(nums[i] * nums[j]);
        }

        sort(productPairs.begin(), productPairs.end());

        int lastProduct = -1;
        int sameProductCount = 0;

        for (int i = 0; i < productPairs.size(); i++) {
            if (productPairs[i] == lastProduct)
                sameProductCount++;
            else {
                int equalProductPairs = sameProductCount * (sameProductCount - 1) / 2;
                result += 8 * equalProductPairs;
                lastProduct = productPairs[i];
                sameProductCount = 1;
            }
        }
        int equalProductPairs = sameProductCount * (sameProductCount - 1) / 2;
        result += 8 * equalProductPairs;
        return result;
    }
};