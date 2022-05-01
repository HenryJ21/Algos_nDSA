//link is  https://practice.geeksforgeeks.org/problems/rod-cutting0840/1/


class Solution{
  public:
    int cutRod(int price[], int n) {
        int W=n;
        int dp[n+1][W+1];
        int wt[n];
        for(int i=0;i<n;i++){
            wt[i] = i+1;
        }
        
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int j=0;j<=W;j++){
            dp[0][j] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(wt[i-1]<=j){
                    dp[i][j] = max(price[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        
        return dp[n][W];
    }
};