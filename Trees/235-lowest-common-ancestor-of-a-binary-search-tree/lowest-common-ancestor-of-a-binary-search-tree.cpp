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
        
        if(p->val < root -> val && q -> val < root -> val)
        {
           TreeNode* leftAns = lowestCommonAncestor( root -> left , p , q);
            return leftAns;
        }
        
        if(p->val > root -> val && q -> val > root -> val)
        {
           TreeNode* rightAns = lowestCommonAncestor( root -> right , p, q);
            return rightAns;
        }
        
        return root ;
    }
};

//ERROR THAT I HAD MADE 

/*


 p->right , q->right ye kyu kar rha tha p and q hi bas pass karna tha in recursive function

root kyu return kar rahe hai . dry run karoge tabhi samjhoge.



*/

//APPROACH
/*
The approach used in this code is a recursive traversal of the binary search tree (BST) to find the lowest common ancestor (LCA) of two given nodes, p and q.

The algorithm compares the values of p and q with the current root node and proceeds to the left or right subtree accordingly.

The recursion continues until a common ancestor is found, and the algorithm returns the LCA.
*/

//THINGS YOU LEARNED
/*
1. The code uses a recursive approach to find the lowest common ancestor in a binary search tree.
2. It leverages the properties of a BST, moving to the left or right subtree based on the values of p and q.

3. tree k question bas 4 mei se ek tareeke se hote hai fixed pattern.
*/

//CORNER CASES
/*
1. The code handles the case where the root of the BST is null, returning NULL to indicate an invalid result.
*/

//TIME COMPLEXITY - O(H)
/*
The time complexity is O(H), where H is the height of the binary search tree. In the worst case, the algorithm traverses the height of the tree to find the lowest common ancestor.
*/

//SPACE COMPLEXITY - O(H)
/*
The space complexity is O(H), where H is the height of the binary search tree. The recursive calls use the call stack, and in the worst case, the space required is proportional to the height of the tree.
*/
