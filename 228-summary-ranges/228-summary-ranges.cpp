class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        
        int i=0;
        vector<string>res;
        
        while(i<n){
            int curr=nums[i];
            int j=i+1;
            while(j<n and i<n and nums[j]==nums[i]+1){
                i++;
                j++;
            }
            
           string subRes=" ";
           if(curr != nums[i]) subRes=to_string(curr) + "->" + to_string(nums[i]);
            else  subRes=to_string(curr);
            
            i++;
            res.push_back(subRes);
        }
        
        return res;
        
        
        
    }
};