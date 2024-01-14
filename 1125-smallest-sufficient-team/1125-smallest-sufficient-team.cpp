class Solution {
public:
    vector<int> ans;
    
    void dfs(int mask,vector<int> &curr_ans,vector<int> &skills,int n){
        
        //base case
        if(mask == (1<<n)-1){
            
            if(ans.size()==0 or curr_ans.size()<ans.size())ans= curr_ans;
            return;
        }
        
        //recursive case
        int required;
        int indx=0;
        
        while(mask & (1<<indx) and mask != (1<<n)-1){
            
            indx++;
        }
        
        required= indx;
        
        if(!ans.empty() and curr_ans.size()>=ans.size())return;
        
        for(int i=0;i<skills.size();i++){
            
            if(skills[i] & (1<<required)){
                
                curr_ans.push_back(i);
                dfs(mask|skills[i],curr_ans,skills,n);
                curr_ans.pop_back();
            }
        }
        
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n= req_skills.size();
        
        unordered_map<string,int> h;
        for(int i=0;i<n;i++){
            
            auto skill= req_skills[i];
            h[skill]= i;
        }
        
        vector<int> skills(people.size(),0);
        for(int i=0;i<people.size();i++){
            
            for(auto skill:people[i]){
                
                int indx= h[skill];
                skills[i]|= (1<<indx);
            }
        }
        
        // for(int i=0;i<people.size();i++)cout<<skills[i]<<endl;
        
        vector<int> curr_ans;
        dfs(0,curr_ans,skills,n);
        
        return ans;
    }
};