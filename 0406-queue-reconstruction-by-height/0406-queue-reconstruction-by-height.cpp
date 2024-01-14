class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])return a[1]<b[1];
        
        return a[0]<b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        
        sort(people.begin(),people.end(),comp);
        
        vector<vector<int>>output(n,vector<int>(2,-1));
        
        for(int i=0;i<n;i++){
            int requiredHeight=people[i][0];
            int requiredCount=people[i][1];
            int count=0;
            for(int j=0;j<n;j++){
                
                 if(count==requiredCount and output[j][0]==(-1)){
                    output[j][0]=people[i][0];
                    output[j][1]=people[i][1];
                     break;
                }
                
                if(output[j][0]==(-1))count++;
                else if(output[j][0]==requiredHeight)count++;
                
               
            }
        }
        
        return output;
        
    }
};