class Solution {
public:
    void utility(int indx,string s,string out,vector<string>&ans)
    {
        //base case
        if(indx==s.length())
        {
            ans.push_back(out);
            return;
        }
        //recursive case
        if(!isdigit(s[indx]))
        {
            //2 choices--->uppercase or lowercase
            
            out.push_back(tolower(s[indx]));
            utility(indx+1,s,out,ans);
            out.pop_back();
            out.push_back(toupper(s[indx]));
            utility(indx+1,s,out,ans);
            out.pop_back();
            
        }
        else
        {
            out.push_back(s[indx]);
            utility(indx+1,s,out,ans);
            out.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        int indx=0;
        vector<string>ans;
        string out="";
        utility(indx,s,out,ans);
        return ans;
        
    }
};