class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
      int sum=0;
      int maxi=0;
      if(nums.size()<=1)
      return nums[0];
      for(int i=0;i<nums.size()-1;i++){
        if(nums[i]<nums[i+1]){
            sum=sum+nums[i];
        }
        else{
            sum=sum+nums[i];
          maxi=max(sum,maxi);
         
          sum=0;
          
        }
      }  
      sum=sum+nums.back();
      return max(maxi,sum);
    }
};