class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n= nums.size();
        
        int remain= k;
        stack<int> s;
        
        for(int i=0;i<n;i++){
            
            while(!s.empty() and nums[i]<s.top() and nums.size()-1-i>=remain){
                
                s.pop();
                remain++;
            }
            
            if(remain>0){
                s.push(nums[i]);
                remain--;
            }
        }
        
        vector<int> res;
        
        while(!s.empty()){
            
            res.push_back(s.top());
            s.pop();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
        
    }
};