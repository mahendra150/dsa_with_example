class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
         vector<vector<int>>ans;
        if(m*n != original.size())return {};
        for(int i=0;i<m;i++)
        {
            vector<int>temp;
            for(int j=i*n;j<(i*n+n);j++)
            {
                temp.push_back(original[j]);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
        
    }
};