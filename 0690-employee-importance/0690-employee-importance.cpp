/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> h;
        
        //Creating the Graph
        for(auto employee:employees){
            h[employee->id]= employee;
        }
        
        //Traversal in a BFS fashioned manner
        
        queue<Employee*> q;
        
        q.push(h[id]);
        int totalImportance=0;
        
       while(!q.empty()){
           auto node= q.front();
           q.pop();
           
           totalImportance+= node->importance;
           
           for(auto nbr: node->subordinates){
               q.push(h[nbr]);
           }
       }
        
        return totalImportance;
        
    }
};