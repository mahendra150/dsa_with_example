class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        
        unordered_map<char,int>freq;
        
        for(int i=0;i<n;i++)freq[s[i]]++;
        
        set<char>st;
        int valid=0;
        unordered_map<char,int>window;
        int indx=(-1);
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            window[s[i]]++;
            if(window[s[i]]==freq[s[i]])valid++;
            st.insert(s[i]);
            if(valid==st.size()){
                indx==(-1)?(ans.push_back(i+1)):ans.push_back(i-indx);
                st.clear();
                window.clear();
                valid=0;
                indx=i;
            }
            
        }
        
        return ans;
        
        
        
    }
};