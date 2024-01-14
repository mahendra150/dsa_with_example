// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		 int n=s.length();
		    vector<string>ans;
		    for(int i=0;i<(1<<n);i++)
		    {
		        string res="";
		        for(int bit=0;bit<n;bit++)
		        {
		            if((i&(1<<bit)))res+=s[bit];
		        }
		       if(res.length()>0) ans.push_back(res);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends