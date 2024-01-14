class Solution {
public:
    string utility(string &word){
        
        auto temp= word;
        reverse(temp.begin(),temp.end());
        
        return temp;
    }
    int longestPalindrome(vector<string>& words) {
        int n= words.size();
        
        unordered_map<string,int> freq;
        for(int i=0;i<n;i++){
            
            auto word= words[i];
            freq[word]+=1;
        }
        
        int res=0;
        int middle=0;
        for(auto i:freq){
            
            auto word= i.first;
            auto rev= utility(word);
            
            if(word != rev){
                
                if(freq.count(rev)){
                    
                    res+= min(freq[word],freq[rev]);
                }
            }
            else{
                
                auto even= (freq[word]/2)*2;
                if(freq[word] & 1){
                    //odd number of "aa"
                    
                    res+= even;
                    middle=1;
                    
                }
                else{
                    // Even number of "aa"
                    
                    res+= even;
                }
            }
        }
        
        res+= middle;
        
        return 2*res;
        
    }
};