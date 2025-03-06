class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pro ;
        int ans = nums[0];   
         
        for(int i = 0; i< nums.size(); i++){

            pro = pro + nums[i];
            
            if(pro > ans){
                ans = pro;
            }

            if(pro<0){
                pro = 0;
            }
        }
        return ans;
    }
    
};