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
    typedef pair<int,ListNode*>node;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         int n=lists.size();
        if(n==0)return NULL;
        priority_queue<node,vector<node>,greater<node>>q;
        for(int i=0;i<n;i++)
        {
            auto head=lists[i];
            if(head)
            {
            q.push({head->val,head});
            }
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(!q.empty())
        {
            auto p=q.top();
            q.pop();
          ListNode* n=new ListNode(p.first);
            if(!head)head=tail=n;
            else
            {
                tail->next=n;
                tail=n;
                }
            auto temp=p.second;
            if(temp->next)
            {
                q.push({temp->next->val,temp->next});
            }
        }
        return head;
        
        
        
    }
};