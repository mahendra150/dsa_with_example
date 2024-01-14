class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n= nums.size();
        
        stack<long long> s;
        long long res= 0;
        
        for(int i=n-1;i>=0;i--){
            
            if(s.empty()){
                
                s.push(nums[i]);
            }
            else if(nums[i]>s.top()){
                
                s.push(nums[i]);
            }
            else{
                
                auto val= s.top();
                s.pop();
                val+= (nums[i]);
                s.push(val);
            }
            
            res= max(res,s.top());
        }
        
        return res;
        
    }
};