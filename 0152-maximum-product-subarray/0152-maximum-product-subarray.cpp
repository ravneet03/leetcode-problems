class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pro =1 ;
        int ans = nums[0];
        int pro1 =1 ;
        int ans1 = nums[0];
        if (nums.size() ==1){
            return nums[0];
        }   
        for(int i = 0; i< nums.size(); i++){

            pro = pro * nums[i];
            
            ans = max(pro,ans);
            if(pro==0){
                pro = 1;
            }
        }
        for(int i = nums.size()-1; i>0; i--){

            pro1 = pro1 * nums[i];
            ans1 = max(pro1,ans1);
            if(pro1==0 ){
                pro1 = 1;
            }
        }
        return max(ans,ans1);
    }
};  