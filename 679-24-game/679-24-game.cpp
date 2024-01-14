class Solution {
public:
    vector<double> compute(double x,double y){
        return {x+y,x-y,y-x,x*y,x/y,y/x};
    }
    bool dfs(vector<double> &nums){
        //base case
        if(nums.size()==1)return abs(nums[0]-24)<0.001;
            
        //recursive case
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                double val1=nums[i];
                double val2=nums[j];
                
                vector<double>res;
                for(auto ans:compute(val1,val2)){
                    res.clear();
                    res.push_back(ans);
                    
                    for(int k=0;k<n;k++){
                        if(k!=i and k!=j)res.push_back(nums[k]);
                    }
                    
                    if(dfs(res))return true;
                }
            }
        }
        
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        
        vector<double>nums;
        
        for(auto i:cards){
            nums.push_back(i*1.0);
        }
       
        
        return dfs(nums);
        
    }
};