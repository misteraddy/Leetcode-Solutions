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
    
    bool isSymmetricChecker(TreeNode* p , TreeNode* q)
    {
        
        //p is null and q is null
        
        if(!p && !q)
        {
            return true;
        }
        
        if(p && q)
        {
            return (p -> val == q -> val) && isSymmetricChecker(p -> left,q->right) && isSymmetricChecker(p -> right, q -> left);
        }
        
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        
        bool ans = isSymmetricChecker(root -> left,root -> right);
        
        return ans ;
    }
};


// APPROACH
/*
   The code checks whether a given binary tree is symmetric. It uses a helper function 'isSymmetricChecker'
   that recursively compares the left subtree of the root with the right subtree, ensuring symmetry.
   The main function 'isSymmetric' initiates the comparison using the root's left and right subtrees.
*/

// THINGS YOU LEARNED
/*
   1. The code employs a recursive approach to check for symmetry in a binary tree.
   2. It uses a helper function to perform the recursive comparison between the left and right subtrees.
   3. The symmetry is checked by ensuring that corresponding nodes in the left and right subtrees have equal values.
*/

// CORNER CASES
/*
   1. The code correctly handles the case where both 'p' and 'q' are NULL, indicating symmetry.
   2. It accounts for the case when one of 'p' or 'q' is NULL while the other is not, indicating asymmetry.
   3. The code ensures the recursive calls are structured to validate the symmetry of the entire tree.
*/

// TIME COMPLEXITY - O(N)
/*
   N represents the number of nodes in the binary tree. The code performs a recursive traversal of each node
   exactly once. Therefore, the time complexity is O(N).
*/

// SPACE COMPLEXITY - O(H)
/*
   H represents the height of the binary tree. The space complexity is determined by the maximum depth
   of the recursive call stack. In the worst case, for an unbalanced tree, the space complexity is O(H).
   However, for a balanced tree, the space complexity is O(log N).
*/
