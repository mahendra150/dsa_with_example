class Solution {
public:
    int dp[41][41];
	int maxi[41][41];
    
    int dfs(int left,int right){
        //base case
        if(left==right)return 0;
        //recursive case
        
        if(dp[left][right] != (-1))return dp[left][right];
        
        //start   mid   and    mid+1    end
        //left    i     and    i+1      right
        
        int ans=INT_MAX;
        for(int i=left;i<right;i++){
            
            ans=min(ans, maxi[left][i] * maxi[i+1][right] + dfs(left,i) + dfs(i+1,right));
        }
        
        
        return dp[left][right]=ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        
        int left=0,right=n-1;
        
        for(int i=0;i<n;i++){
            maxi[i][i]=arr[i];
            for(int j=i+1;j<n;j++){
                maxi[i][j]=max(maxi[i][j-1],arr[j]);
            }
        }
        
        memset(dp,(-1),sizeof(dp));
        return dfs(left,right);
        
    }
};