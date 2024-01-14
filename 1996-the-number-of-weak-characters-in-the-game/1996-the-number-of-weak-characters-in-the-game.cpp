class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        
        if(a[0]==b[0])return a[1]<b[1];
        
        return a[0]>b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n= properties.size();
        
        // properties[i] --> [ attacki , defensei ];
        
        sort(properties.begin(),properties.end(),comp);
        
        int maxDefense= 0;
        int res=0;
        
        for(int i=0;i<n;i++){
            
            auto defense= properties[i][1];
            if(defense<maxDefense)res+=1;
            
            maxDefense=max(maxDefense,defense);
        }
        
        return res;
    }
};