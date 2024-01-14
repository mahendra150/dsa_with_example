

class Solution {
public:
    void dfs(int i,vector<string> &curr_ans,vector<string> &arr,int &ans){
        //base case
        if(i==arr.size()){
            
            vector<int> freq(26,0);
            string subRes="";
            for(int i=0;i<curr_ans.size();i++){
                subRes+=curr_ans[i];
            }
            
            for(auto ch:subRes){
                freq[ch-97]+=1;
            }
            int count=0;
            
           for(int i=0;i<26;i++){
               if(freq[i]==1)count+=1;
               
               else if(freq[i]>1){
                   count=0;
                   return;
               }
           }
            
            ans=max(ans,count);
            return;
        }
        
        //recursive case  --> Classical Subsequence
        
        curr_ans.push_back(arr[i]);
        dfs(i+1,curr_ans,arr,ans);
        curr_ans.pop_back();
        
         dfs(i+1,curr_ans,arr,ans);
        
        
    }
    int maxLength(vector<string>& arr) {
        int i=0;
        vector<string>curr_ans;
        
        int ans= 0;
        dfs(i,curr_ans,arr,ans);
        
        return ans;
        
    }
};