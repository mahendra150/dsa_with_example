typedef pair<string,pair<int,int>> node;
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        int size= logs.size();
        
        stack<node> st;
        vector<int> res(n,0);
        
         for(int i=0;i<size;i++){
             
             auto data= logs[i];
             stringstream s(data);
             string str;
             vector<string> nums;
             while(getline(s,str,':')){
                 
                 nums.push_back(str);
             }
             
             auto id= stoi(nums[0]);
             auto functionCall= nums[1];
             auto time= stoi(nums[2]);
             
             // cout<<functionCall<<" "<<id<<" "<<time<<endl;
             if(functionCall=="start"){
                 
                 st.push({functionCall,{id,time}});
             }
             else{
                 
                 auto timeTaken=0;
                 if(st.top().second.first==id){
                     
                      timeTaken= time- st.top().second.second + 1;
                     st.pop();
                     
                    res[id]+= timeTaken;
                 }
                 
                 if(!st.empty()){
                     
                     if(st.top().first=="start") res[st.top().second.first]-= timeTaken;
                 }
             }
             
        }
        
        return res;
    }
};