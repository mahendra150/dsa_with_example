class Solution {
public:
    vector<int> visited;
    
    bool dfs(int i,int currSum,long long int targetSum,int k,vector<int> &nums,int n){
        
        //base case
        
        if(k==1)return true;
        if(currSum==targetSum)return dfs(0,0,targetSum,k-1,nums,n);
        
        //recursive case
        
        for(int j=i;j<n;j++){
            
            int candidate= nums[j];
            if(!visited[j] and currSum + candidate<=targetSum){
                
                visited[j]= true;
                if(dfs(j+1,currSum+candidate,targetSum,k,nums,n))return true;
                visited[j]= false;
            }
        }
        
        return false;
        
    }
    bool makesquare(vector<int>& matchsticks) {
        int n= matchsticks.size();
        vector<int> nums= matchsticks;
        
        int k= 4;
        visited.resize(n,false);
        
        long long int sum=0;
        for(int i=0;i<n;i++)sum+= nums[i];
        
        if(sum % 4 != 0 or n<4)return false;
        
        int targetSum= (sum)/4;
        return dfs(0,0,targetSum,k,nums,n);
    }
};