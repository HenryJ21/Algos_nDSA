#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<long long,int> um;
        
        int maxLen = 0;
        long long curr_sum = 0;
        um.insert(make_pair(0, -1));
  
        
        for(int i=0;i<N;i++){
            curr_sum+=A[i];
            
            if(um.find(curr_sum) == um.end()){
                um.insert(make_pair(curr_sum,i));
            }
            
            
            if(um.find(curr_sum - K) != um.end()){
                maxLen = max(maxLen,i - um[curr_sum-K]);
            }
            
            
        }
        
        return maxLen;
        
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends