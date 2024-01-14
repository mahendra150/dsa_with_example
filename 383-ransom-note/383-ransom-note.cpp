class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>window;
        unordered_map<char,int>need;
        
        for(int i=0;i<ransomNote.length();i++){
            char ch=ransomNote[i];
            need[ch]++;
        }
        
        int valid=0;
        
        for(int i=0;i<magazine.length();i++){
            char ch=magazine[i];
            window[ch]++;
            if(need.count(ch)){
                if(need[ch]==window[ch])valid++;
            }
        }
        
       if(valid==need.size())return true;
        
        return false;
        
        
    }
};