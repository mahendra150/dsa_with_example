class Solution {
public:
    int upperLimit;
    int lowerLimit;
    
    void dfs(int number,int n,int k,vector<int> &res){
        
        //base case
        
        if(n==0)res.push_back(number);
        
        //recursive case
        
        for(int i=0;i<10;i++){
            
            if(number==0 and i==0)continue;
            
            else if(number==0 and i!=0){
                dfs(i,n-1,k,res);
            }
            
            else if( abs(i-(number%10)) == k ){
                
                if(number>=lowerLimit and number<=upperLimit)dfs(number*10+i,n-1,k,res);
            }
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> res;
        upperLimit= (pow(2,31)-1)/10;;
        lowerLimit= (-pow(2,31))/10;;
        
        //Edge Cases
        if(n==0)return {};
        if(n==1)res.push_back(0);
        
        int number=0;
        dfs(number,n,k,res);
        
        return res;
        
    }
};