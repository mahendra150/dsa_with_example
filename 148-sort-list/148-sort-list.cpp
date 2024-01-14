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
     ListNode* merge( ListNode* h1, ListNode* h2)
     {
         //base case
         if(!h1)return h2;
         if(!h2)return h1;
         //recursive case
          ListNode* nH=NULL;
         if(h1->val <h2->val)
         {
              nH=h1;
             nH->next=merge(h1->next,h2);
         }
         else
         {
              nH=h2;
             nH->next=merge(h1,h2->next);
         }
         return nH;
     }
    
     ListNode* middlePoint( ListNode* head)
     {
          ListNode* s=head;
          ListNode* f=head;
         ListNode* prev=head;
         while(f != NULL and f->next!= NULL)
         {
             prev=s;
             s=s->next;
             f=f->next->next;
         }
         return prev;
     }
     ListNode* mergeSort( ListNode* head)
     {
         //base case
         if(!head or !head->next)return head;
         
         //recursive case
          
         ListNode* a=head;
         ListNode* b=head;
         ListNode* prev=middlePoint(head);
         b=prev->next;
         prev->next=NULL;
         a=mergeSort(a);
         b=mergeSort(b);
        ListNode* newHead=merge(a,b);
         return newHead;
     }
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)return head;
        return mergeSort(head);
        
    }
};