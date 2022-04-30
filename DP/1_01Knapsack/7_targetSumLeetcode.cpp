
//link is https://leetcode.com/problems/target-sum/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int tsum,sum;
        tsum = 0;
        
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            tsum+=nums[i];
        }
        if(tsum<target){
            return 0;
        }
        
        if((target+tsum)%2==1){
            return 0;
        }
        sum = (target+tsum)/2;
        if(sum<0){
            return 0;
        }
        
        int dp[n+1][sum+1];
        
        int counter = 0;
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            if(nums[i-1]==0){
                counter++;
            }
            dp[i][0] = pow(2,counter);
        }
        
        for(int j=1;j<=sum;j++){
            dp[0][j] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
        
        
    }
};