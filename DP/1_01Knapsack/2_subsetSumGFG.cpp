// link is https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        int dp[n+1][sum+1];
        
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int j=1;j<=sum;j++){
            dp[0][j] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j){
                    dp[i][j] = max(dp[i-1][j-arr[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        if(dp[n][sum]==0){
            return false;
        }
        else{
            return true;
        }
        
    }
};