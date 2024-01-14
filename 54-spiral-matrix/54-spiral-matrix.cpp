class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int t=0,b=n-1,l=0,r=m-1;
        int dir=0;
        vector<int>ans;
        while(t<=b and l<=r)
        {
            if(dir==0)
            {
                for(int j=l;j<=r;j++)
                {ans.push_back(matrix[t][j]);
                }
                t++;
                dir=1;
            }
            else if(dir==1)
            {
                for(int i=t;i<=b;i++)
                {
                    ans.push_back(matrix[i][r]);
                }
                r--;
                dir=2;
            }
            else if(dir==2)
            {
                for(int j=r;j>=l;j--)
                {
                    ans.push_back(matrix[b][j]);
                }
                b--;
                dir=3;
            }
            else if(dir==3)
            {
                for(int i=b;i>=t;i--)
                {
                    ans.push_back(matrix[i][l]);
                }
                l++;
                dir=0;
            }
        }
        return ans;
        
    }
};