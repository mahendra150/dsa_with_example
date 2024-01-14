class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        
        int ans=0;
        int indx=0;
        
        for(int i=0;i<n;i++){
            
            int currAns=0;
            for(int j=0;j<m;j++){
                
                if(mat[i][j])currAns+=1;
            }
            
            if(currAns>ans){
                
                ans=currAns;
                indx=i;
            }
        }
        
        return {indx,ans};
    }
};