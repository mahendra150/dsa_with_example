// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
void dfs(int i,int j,int n,int m,vector<vector<int>>& image,int original,int newColor)
{
    //base case
    if(i<0 or i>=n or j<0 or j>=m or image[i][j]!=original)return;
    //recursive case
    image[i][j]=newColor;
    dfs(i-1,j,n,m,image,original,newColor);
    dfs(i+1,j,n,m,image,original,newColor);
    dfs(i,j-1,n,m,image,original,newColor);
    dfs(i,j+1,n,m,image,original,newColor);
    
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
       if(image[sr][sc]==newColor)return image;
       int n=image.size();
       int m=image[0].size();
       int original=image[sr][sc];
       dfs(sr,sc,n,m,image,original,newColor);
       return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends