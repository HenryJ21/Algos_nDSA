// link is https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1


class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0,tsum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    tsum=sum;
	    
	    if(sum%2==0){
	        sum=sum/2;
	    }
	    else{
	        sum = sum/2 + 1;
	    }
	    
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
	                dp[i][j] = max(dp[i-1][j-arr[i-1]],dp[i-1][j]);
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    
	    int i = n, j =sum;
	    while(true){
	        if(dp[i][j]==1){
	            return abs(tsum - 2*j);
	        }
	        if(j==0){
	            return tsum;
	        }
	        else{
	            j--;
	        }
	    }
	    
	} 
};