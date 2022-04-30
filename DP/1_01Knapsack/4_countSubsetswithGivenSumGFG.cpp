//link is https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        if(sum%2==0){
            sum = sum/2;
            int dp[n+1][sum+1];
            for(int i=0;i<=n;i++){
                dp[i][0] = 1;
            }
            for(int j=1;j<=sum;j++){
                dp[0][j] = 0;
            }
            
            for(int i=1;i<=n;i++){
                for(int j=1;j<=sum;j++){
                    if(nums[i-1]<=j){
                        dp[i][j] = max(dp[i-1][j-nums[i-1]], dp[i-1][j]);
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            
            if(dp[n][sum]==1){
                return true;
            }
            else{
                return false;
            }
            
        }
        else{
            return false;
        }
        
    }
};