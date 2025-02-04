/*class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int> ans(nums.size(),0);
        int pos = 0, neg = 1;
        
        for (int i = 0; i < nums.size(); i++){
            if(nums[i]>0){
                ans[pos] = nums[i];
                pos+=2;
            }else{
                ans[neg] = nums[i];
                neg+=2;
            }
        }
        return ans;

    }
};*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int posCount = 0;
        int negCount = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] > 0){
                posCount++;
                ans[(posCount * 2)-2] = nums[i];
            }else{
                 negCount++;
                ans[(negCount * 2)-1] = nums[i];
            }
        }

        return ans;
    }
};