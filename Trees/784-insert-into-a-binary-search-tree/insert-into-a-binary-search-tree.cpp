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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root == NULL)
        {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        
        if(root -> val == val)
        {
            return root;
        }
        else if(root -> val < val)
        {
            if(root -> right != NULL)
            {
                root -> right = insertIntoBST(root -> right,val);
            }
            else 
            {
                TreeNode* newNode = new TreeNode(val);
                root -> right = newNode ;
            }
        }
        else
        {
            if(root -> left != NULL)
            {
                root -> left = insertIntoBST(root -> left,val);
            }
            else
            {
                TreeNode* newNode = new TreeNode(val);
                root -> left = newNode ;
            }
        }
        
        return root ;
    }
};

//ERROR THAT I MADE WHILE SOLVING 
/*

TreeNode * newNode(val) isse soch rahe the ki memory allocate hogi but ye toh bas declaration hai of the function for creating the node and return its address .

TreeNode* newNode = new TreeNode(42);

*/