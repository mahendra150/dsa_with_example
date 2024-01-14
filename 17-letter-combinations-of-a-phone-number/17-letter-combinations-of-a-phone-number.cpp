class Solution {
public:
    unordered_map<int, string> keys = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };
    void phoneKeypad(string digits,string output,vector<string>&ans,int i,int j)
    {
        //base case
        if(digits[i]==NULL)
        {
            ans.push_back(output);
            return;
        }
        
        //recursive case
        int indx=digits[i]-48;
        for(int k=0;keys[indx][k]!=NULL;k++)
        {
            output.push_back(keys[indx][k]);
            phoneKeypad(digits,output,ans,i+1,j+1);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits=="")
        {
            return ans;
        }
        int i=0,j=0;
        string  output;
        phoneKeypad(digits,output,ans,i,j);
        return ans;
        
    }
};