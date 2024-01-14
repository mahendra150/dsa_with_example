//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    int n=S.length();
    set<char>s;
    
    int l=0,r=0;
    
    int maxLen=0;
    while(r<n){
        while(s.find(S[r]) != s.end()){
            s.erase(s.find(S[l]));
            l++;
        }
        
        maxLen=max(maxLen,r-l+1);
        s.insert(S[r]);
        r++;
        // maxLen=max(maxLen,r-l+1);
    }
    
    return maxLen;
}