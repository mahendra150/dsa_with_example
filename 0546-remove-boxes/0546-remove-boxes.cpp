class Solution {
public:
    int dfs(int l,int r,int k,vector<int> &boxes){
        //base case
        if(l>r)return 0;
        
        //recursive case
        if(dp[l][r][k] != (-1))return dp[l][r][k];
        
        int tmpl=l,tmpk=k;
        while(l+1<=r and boxes[l]==boxes[l+1]){
            l++;
            k++;
        }
        
        
        int ans= (k+1)*(k+1) + dfs(l+1,r,0,boxes);
        
        for(int mid=l+1;mid<=r;mid++){
            
            if(boxes[l]==boxes[mid]){
                ans=max(ans, dfs(l+1,mid-1,0,boxes) + dfs(mid,r,k+1,boxes));
            }
        }
        
        return dp[tmpl][r][tmpk]=ans;
    }
    vector<vector<vector<int>>> dp;
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        
        int l=0,r=n-1,k=0;
        dp.resize(105,vector<vector<int>>(105,vector<int>(105,-1)));
        
        return dfs(l,r,k,boxes);
        
    }
};