/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>visited;
        Node* temp=head;
        while(temp)
        {
            Node* newNode=new Node(temp->val);
            visited[temp]=newNode;
            temp=temp->next;
        }
        
        Node* nH=NULL;
        Node* nT=NULL;
        temp=head;
        while(temp)
        {
            if(!nH)
            {
                nH=nT=visited[temp];
                if(temp->random)nH->random=visited[temp->random];
                else nH->random=NULL;
            }
            else
            {
                nT->next=visited[temp];
                nT=nT->next;
                if(temp->random)nT->random=visited[temp->random];
                else nT->random=NULL;
            }
            temp=temp->next;
        }
        
        return nH;
        
    }
};