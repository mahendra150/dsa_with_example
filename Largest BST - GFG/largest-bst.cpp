// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    vector<int> utility(Node* root)
    {
        //base case
        if(!root)
        {
            return {1,0,INT_MAX,INT_MIN};
        }
        if(!root->left and !root->right)
        {
            return {1,1,root->data,root->data};
        }
        //recursive case
        vector<int>lst=utility(root->left);
        vector<int>rst=utility(root->right);
        
        if(lst[0]==1 and rst[0]==1)
        {
            if(root->data >lst[3] and root->data < rst[2])
            {
                int minVal=lst[2];
                int maxVal=rst[3];
                if(minVal==INT_MAX)
                {
                    minVal=root->data;
                }
                if(maxVal==INT_MIN)
                {
                    maxVal=root->data;
                }
                return {1,1+lst[1]+rst[1],minVal,maxVal};
            }
        }
        return {0,max(lst[1],rst[1]),0,0};
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	//0 isBst
    	//1 size of the bst
    	//2 minVal
    	//3 maxVal
        vector<int>ans=	utility(root);
        return ans[1];
    	
    	
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends