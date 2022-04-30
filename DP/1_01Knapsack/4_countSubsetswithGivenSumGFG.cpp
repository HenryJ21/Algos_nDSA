//link is https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1


class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        int moda = 1000000007;
        
        int dp[n+1][sum+1];
        dp[0][0] = 1;
        int counter = 0;
        for(int i=1;i<=n;i++){
            if(arr[i-1]==0){
                counter++;
            }
            dp[i][0] = pow(2,counter);
        }
        for(int j=1;j<=sum;j++){
            dp[0][j] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j){
                    dp[i][j] = (dp[i-1][j-arr[i-1]]%moda+dp[i-1][j]%moda)%moda;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
	}
	  
};
