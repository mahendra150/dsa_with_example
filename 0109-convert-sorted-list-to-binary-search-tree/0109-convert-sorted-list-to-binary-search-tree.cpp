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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> middleOfLinkedList(ListNode* head){
        
        ListNode* s=head;
        ListNode* p=head;
        ListNode* f=head;
        
        while(f and f->next){
            
            p=s;
            s=s->next;
            f=f->next->next;
        }
        
        return {s,p};
    }
    TreeNode* mergeSort(ListNode* head){
        
        //base case
        if(!head)return NULL;
        if(!head->next)return new TreeNode(head->val);
            
        //recursive case
        auto a= head;
        auto b=head;
        auto val= middleOfLinkedList(head);
        
        auto mid= val[0];
        auto prev= val[1];
        
        b= mid->next;
        prev->next= NULL;
        
        TreeNode* root= new TreeNode(mid->val);
        
        root->left= mergeSort(a);   // start mid-1
        root->right= mergeSort(b);  // mid+1 end
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
        return mergeSort(head);
    }
};