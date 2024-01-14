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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head or !head->next)return head;
            ListNode* sentinel=new ListNode();
            sentinel->next=head;
            ListNode* temp=sentinel;
        
        for(int i=0;i<left-1;i++)temp=temp->next;
        ListNode* l=temp->next;
        ListNode* p=temp;
        ListNode* c=p->next;
        while(left<=right and c!=NULL)
        {
            ListNode* n=c->next;
            c->next=p;
            p=c;
            c=n;
            left++;
        }
        temp->next=p;
        l->next=c;
        return sentinel->next;
        
        
    }
};