class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        
        int totalSize=0;
        for(int i=0;i<n;i++)totalSize++;
        if(totalSize%groupSize != 0)return false;
        
        multiset<int>s(hand.begin(),hand.end());
        
        int divisions=totalSize/groupSize;
        
        while(!s.empty()){
            int tempGroupSize=groupSize;
            int num= *(s.begin());
                while(tempGroupSize){
              //  cout<<num<<" ";
                auto address=s.find(num);
                    if(address != s.end())s.erase(address);
                    tempGroupSize--;
                if(s.count(num+1)>0){
                num=num+1;
            }
                else break;
                }
          //  cout<<endl;
           if(tempGroupSize==0)divisions--;
            if(divisions==0)return true;
        }
        
        return false;
        
    }
};