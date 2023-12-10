/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL)
        {
            return NULL;
        }
        
        
        if(root -> val == p -> val)
        {
            return p ;
        }
        
        if(root -> val == q -> val)
        {
            return q ;
        }
        
        TreeNode* leftAns = lowestCommonAncestor(root -> left,p,q);
        
        TreeNode* rightAns = lowestCommonAncestor(root -> right,p,q);
        
        if(leftAns == NULL && rightAns == NULL)
        {
            return NULL ;
        }
        else if(leftAns == NULL && rightAns != NULL)
        {
            return rightAns ;
        }
        else if(leftAns != NULL && rightAns == NULL)
        {
            return leftAns ;
        }
        else
        {
            //leftAns != NULL && rightAns != NULL
            
            return root ;
        }
        
    }
};

// ERROR THAT I HAD MADE
/*
The code has a logical error in handling the case where the common ancestor is not found in either the left or right subtrees.

If both leftAns and rightAns are not equal to null, the code incorrectly returns the root instead of finding the correct common ancestor.
*/

// APPROACH
/*
The code uses a recursive approach to find the lowest common ancestor (LCA) of two nodes, p and q, in a binary tree.
1. If the root is null, return null.
2. If the value of the root is equal to the value of p, return p.
3. If the value of the root is equal to the value of q, return q.
4. Recursively find the LCA in the left and right subtrees.
5. If both leftAns and rightAns are not null, return the root as the LCA.
6. If only leftAns is not null, return leftAns.
7. If only rightAns is not null, return rightAns.
8. If both leftAns and rightAns are null, return null.
*/

// THINGS YOU LEARNED
/*
1. The code doesn't handle the case where the LCA is not found in either the left or right subtrees correctly.
2. The code checks for the equality of node values but doesn't consider the case where one node is an ancestor of the other.
*/

// CORNER CASES
/*
The code may not handle cases where p or q are not present in the tree correctly.
It assumes that the values of p and q are unique in the tree, and it doesn't handle cases where one node is an ancestor of the other.
*/

// TIME COMPLEXITY - O(N)
// The code visits each node in the tree once in the worst case, where N is the number of nodes in the tree.

// SPACE COMPLEXITY - O(H)
// The space complexity is proportional to the height of the recursion stack, where H is the height of the tree.
