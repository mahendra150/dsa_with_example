/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)return NULL;
       // ListNode* sentinel=new ListNode();
       // sentinel->next=head;
        int k=2;
        ListNode* c=head;
        ListNode* nH=head;
        ListNode* p=NULL;
        ListNode* oH=NULL;
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        //check if len is <= to 1    ------> example:  [1]
        if(len<=1)return head;
        while(c!= NULL)
        {
           for(int i=0;i<k;i++)
           {
               ListNode*  n=c->next;
                c->next=p;
                p=c;
                c=n;
               len--;
           }
            
            nH->next=c;
            if(oH==NULL)
            {
                head=p;
            }
            else
            {
                oH->next=p;
            }
            p=nH;
            oH=p;
            nH=c;
            p->next=c;
            if(len/k <=0)break;
        }
        return head;
        
    }
};