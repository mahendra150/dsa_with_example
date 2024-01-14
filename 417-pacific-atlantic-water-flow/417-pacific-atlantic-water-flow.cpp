class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<bool>>&visited,vector<vector<int>>& heights,int pre)
    {
        //base case
        if(i<0 or i>=n or j<0 or j>=m or pre>heights[i][j]  or visited[i][j])return;
        //recurisve case
        visited[i][j]=true;
        
        dfs(i-1,j,n,m,visited,heights,heights[i][j]);
        dfs(i+1,j,n,m,visited,heights,heights[i][j]);
        dfs(i,j-1,n,m,visited,heights,heights[i][j]);
        dfs(i,j+1,n,m,visited,heights,heights[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));
        for(int j=0;j<m;j++)
        {
            dfs(0,j,n,m,pacific,heights,-1);
            dfs(n-1,j,n,m,atlantic,heights,-1);
        }
        for(int i=0;i<n;i++)
        {
            dfs(i,0,n,m,pacific,heights,-1);
            dfs(i,m-1,n,m,atlantic,heights,-1);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vector<int>curr_ans;
                if(pacific[i][j] and atlantic[i][j])
                {
                    curr_ans.push_back(i);
                    curr_ans.push_back(j);
                    ans.push_back(curr_ans);
                    curr_ans.clear();
                }
            }
        }
        return ans;
        
        
    }
};