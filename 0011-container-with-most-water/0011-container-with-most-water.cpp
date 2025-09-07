class Solution {
public:
    int maxArea(vector<int>& height) {
    int l = 0, r = height.size()-1;
    int ans = 0;
    while(l < r) {
        int h = min(height[l], height[r]);
        int width = r - l;
        ans = max(ans, h * width);
        if(height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }
    return ans;
}
};