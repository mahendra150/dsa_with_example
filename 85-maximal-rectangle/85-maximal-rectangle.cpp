class Solution {
public:
    int largestRectangleInHistogram(vector<int> &dp){
        int n=dp.size();
        
        vector<int>nsr(n,-1);
        vector<int>nsl(n,-1);
        
        stack<int>s;
        
        for(int i=0;i<n;i++){
            while(!s.empty() and dp[i]<dp[s.top()]){
                nsr[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        while(!s.empty())s.pop();
        
        for(int i=0;i<n;i++){
            
            while(!s.empty() and dp[i]<dp[s.top()]){
                s.pop();
            }
            if(!s.empty())nsl[i]=s.top();
            
            s.push(i);
        }
        
        for(int i=0;i<n;i++){
            if(nsr[i]==(-1))nsr[i]=n;
            if(nsl[i]==(-1))nsl[i]=(-1);
        }
        
        
        int maxArea=0;
        
        for(int i=0;i<n;i++){
            int  height=dp[i];
            int breadth=nsr[i]-nsl[i]-1;
            int currArea=height*breadth;
            
            maxArea=max(maxArea,currArea);
        }
        
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<int>dp(m,0);
        int maxArea=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')dp[j]++;
                else dp[j]=0;
            }
            int calculatedArea=largestRectangleInHistogram(dp);
            maxArea=max(maxArea,calculatedArea);
        }
        
        
        return maxArea;
        
    }
};