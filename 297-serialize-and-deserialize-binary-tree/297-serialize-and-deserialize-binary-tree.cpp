/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        queue<TreeNode*>q;
        q.push(root);
        string str="";
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            if(!x)str.append("#,");
            else
            {
                str.append(to_string(x->val)+',');
                q.push(x->left);
                q.push(x->right);
            }
        }
        return str;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0)return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
   TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")
            {
                node->left=NULL;
            }
            else
            {
              
            TreeNode* leftNode=new TreeNode(stoi(str));
                node->left=leftNode;
                q.push(leftNode);
            }
            
            getline(s,str,',');
            if(str=="#")
            {
                node->right=NULL;
            }
            else
            {
              TreeNode* rightNode=new TreeNode(stoi(str));
                node->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));