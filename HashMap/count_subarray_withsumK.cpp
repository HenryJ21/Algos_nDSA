class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> um;
        
        um.insert(make_pair(0,1));
        int curr_sum = 0;
        int ans = 0;
        

        um.insert(make_pair(0,1));
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            if(um.find(curr_sum - k) != um.end()){
                ans+=um[curr_sum - k];
            }
            if(um.find(curr_sum) == um.end()){
                um.insert(make_pair(curr_sum,1));
            }
            else{
                um[curr_sum] += 1;
            }
            
            
            
        }
        
        
        
        return ans;
        
        
    }
};