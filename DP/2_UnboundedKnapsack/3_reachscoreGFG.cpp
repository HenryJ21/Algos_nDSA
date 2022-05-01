//link is https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1

long long int count(long long int n)
{
    long long int dp[4][n+1];
    long long int arr[3];
    arr[0] = 3;
    arr[1] = 5;
    arr[2] = 10;
    
    dp[0][0] = 1;
    for(long long int i=1;i<=3;i++){
        dp[i][0] = 1;
    }
    for(long long int j=1;j<=n;j++){
        dp[0][j] = 0;
    }
    
    for(long long int i=1;i<=3;i++){
        for(long long int j=1;j<=n;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i][j-arr[i-1]]+dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[3][n];
    
}