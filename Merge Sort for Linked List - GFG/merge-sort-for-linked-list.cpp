// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* merge(Node* h1,Node* h2)
    {
        //base case
        if(!h1)return h2;
        if(!h2)return h1;
        //recursive case
        Node* nH=NULL;
        if(h1->data<h2->data)
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
    Node* middle(Node* head)
    {
        Node* s=head;
        Node* f=head;
        Node* prev=head;
        while(f != NULL and f->next!=NULL)
        {
            prev=s;
            s=s->next;
            f=f->next->next;
        }
        return prev;
    }
    Node* sort(Node* head)
    {
        //base case 
        if(!head or !head->next)return head;
        //recursive case
        Node* prev=middle(head);
        Node* a=head;
        Node* b=prev->next;
        prev->next=NULL;
        a=sort(a);
        b=sort(b);
        Node* nH=merge(a,b);
        return nH;
    }
    Node* mergeSort(Node* head) {
        // your code here
       return sort(head);
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends