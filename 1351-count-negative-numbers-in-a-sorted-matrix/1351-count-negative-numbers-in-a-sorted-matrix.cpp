class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        //Staircase Search
        
        int i=0,j=m-1;
        int res=0;
        
        while(i<n and j>=0){
            
            if(grid[i][j]<0){
                
                res+=(n-i);
                j--;
            }
            else{
                i++;
            }
        }
        
        return res;
        
    }
};