class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n=nums.size();
        
        double sum= accumulate(nums.begin(),nums.end(),0.0);
        double original=sum;
        
        priority_queue<double>q(nums.begin(),nums.end());
        int res=0;
        
        while(original<2*sum){
            
            double val=q.top();
            q.pop();
            
            val/=2;
            sum-=val;
            q.push(val);
            res+=1;
        }
        
        return res;
        
    }
};