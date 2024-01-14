class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        unordered_map<string,int>freq;
        
        for(auto email:emails){
            string cleanEmail="";
            //Formation of LocalName
            for(auto c:email){
                if(c=='+' or c=='@')break;
                if(c=='.')continue;
                
                cleanEmail+=c;
            }
            //Formation of the whole Email Address
            
            cleanEmail += email.substr(email.find('@'));
            freq[cleanEmail]++;
        }
        
        return freq.size();
        
    }
};