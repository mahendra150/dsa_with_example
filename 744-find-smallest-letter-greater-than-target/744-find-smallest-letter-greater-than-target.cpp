class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int s=0,e=n-1;
        char res=' ';
        while(s<=e)
        {
            int mid=(s+e)/2;

            if(letters[mid]>target)
            {
                res=letters[mid];
                e=mid-1;
            }
            else s=mid+1;
        }
        if(res==' ')return letters[0];
        return res;
        
    }
};