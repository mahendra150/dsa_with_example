class Solution {
public:
    int dfs(int n,int k){
        
        //base case
        
        if(n==0)return 0;
        
        //recursive case
        
        if(k % 2 == 0){
            
            if(dfs(n-1,k/2)==0)return 1;
            else return 0;
        }
        else{
            
            if(dfs(n-1,(k+1)/2)==1)return 1;
            else return 0;
        }
    }
    int kthGrammar(int n, int k) {
        
        n= n-1;
        return dfs(n,k);
    }
};