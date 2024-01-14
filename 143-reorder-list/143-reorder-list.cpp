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
    ListNode* reverse(ListNode* p,ListNode* c)
    {
        while(c!=NULL)
        {
            ListNode* n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }
    void reorderList(ListNode* head) {
        if(!head or !head->next or !head->next->next)return;
        ListNode* temp=head;
        int len=0;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        ListNode* s=head;
        ListNode* f=head;
    //    temp=NULL;
        while(f!= NULL and f->next!=NULL)
        {
            temp=s;
            s=s->next;
            f=f->next->next;
        }
        
        ListNode* p;
        ListNode* c;
        if(len%2==0)
        {
            p=temp;
            c=s;
        }
        else if(len %2 !=0)
        {
            p=s;
            c=s->next;
        }
        ListNode* last=reverse(p,c);
        
        ListNode* l=head;
        ListNode* r=last;
        
     //   ListNode* temp1=l->next;
      //  ListNode* temp2=r->next;
        while(1)
        {
            ListNode* temp1=l->next;
            ListNode* temp2=r->next;
            if( temp1==r or temp2==l)
            {
                 temp1->next=NULL;
                break;
            }
            else if(l==r)
            {
                r->next=NULL;
                break;
            }
            l->next=r;
            r->next=temp1;
            l=temp1;
            r=temp2;
        }
            
        
    }
};