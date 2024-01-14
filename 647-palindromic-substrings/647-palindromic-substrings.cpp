class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int dp[1005][1005];
        memset(dp,(0),sizeof(dp));
        int count=0;
        
        //length->1
        for(int i=0;i<n;i++)
        {dp[i][i]=1;
         count++;
        }
        
        //length->2
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {dp[i][i+1]=1;
             count++;
            }
        }
        
        //length>=3
        
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;
                if(s[i]==s[j] and dp[i+1][j-1]==1)
                {
                  // cout<<"hi";
                    dp[i][j]=1;
                    count++;
                }
            }
        }
        return count;
        
    }
};