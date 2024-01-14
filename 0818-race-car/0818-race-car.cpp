class carAttributes{
public:
    
     int position,speed;
    carAttributes(int position,int speed){
        
        this->position= position;
        this->speed= speed;
    }
};

class Solution {
public:
    bool isPositionNotFarFromTarget(int position,int target){
        
        return abs(target-position)<target;
        
    }
    
    int utility(int target){
        
        int steps=0;
        queue<carAttributes> q;
        unordered_map<string,bool> visited;
        
        string key= to_string(0) + ',' + to_string(1);
        visited[key]= true;
        carAttributes car(0,1);
        q.push(car);
        
        
        while(!q.empty()){
            
            int size= q.size();
            while(size--){
                
                auto node= q.front();
                q.pop();
                
                auto currSpeed= node.speed;
                auto currPosition= node.position;
                
                if(currPosition==target)return steps;
                
                // option1 --> "A"
                
                int nextPosition= currPosition + currSpeed;
                int nextSpeed= currSpeed*2;
                
                carAttributes nextNodeAcc(nextPosition,nextSpeed);
                string nextKey= to_string(nextPosition) + ',' + to_string(nextSpeed);
                
                if(!visited[nextKey] and isPositionNotFarFromTarget(nextPosition,target)){
                    
                    visited[nextKey]= true;
                    q.push(nextNodeAcc);
                }
                
                // option2 --> "R"
                
                nextPosition= currPosition;
                nextSpeed= (currSpeed<0?1:-1);
                
                carAttributes nextNodeRev(nextPosition,nextSpeed);
                nextKey= to_string(nextPosition) + ',' + to_string(nextSpeed);
                
                if(!visited[nextKey] and isPositionNotFarFromTarget(nextPosition,target)){
                    
                    visited[nextKey]= true;
                    q.push(nextNodeRev);
                }
            }
            
            steps+=1;
        }
        
        return (-1);
    }
    int racecar(int target) {
        
        return utility(target);
    }
};