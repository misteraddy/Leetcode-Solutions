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
    
    int diameter = 0 ;
    
    int findHeight(TreeNode* root){
        
        if(root == NULL)
        {
            return 0 ;
        }
        
        int lh = findHeight(root -> left);
        
        int rh = findHeight(root -> right);
        
        int currDiameter = lh + rh ;
        
        if(diameter < currDiameter)
        {
            diameter = currDiameter ;
        }
        
        return max(lh,rh) + 1 ;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        findHeight(root);
        
        return diameter ;
    }
};

// ERROR THAT I HAD MADE
/*
The main error in the code is that the member function findHeight is being called, but it's defined with the wrong name. The function is declared as findHeight, but it's implemented as diameterOfBinaryTree. This inconsistency can lead to confusion and compilation errors.
*/

// APPROACH
/*
The approach of the code is to calculate the height of each subtree while simultaneously updating the diameter of the binary tree.

The findHeight function is a recursive function that computes the height of the current subtree, and the diameter is updated by considering the sum of heights of the left and right subtrees for each node.

kyunki diameter is the sum of the max height of the left subtree and the max height of the right subtree

The final diameter of the binary tree is stored in the class variable 'diameter.'
*/

// THINGS YOU LEARNED
/*
1. Recursive Tree Traversal: The code demonstrates the use of recursive tree traversal to calculate the height of each subtree.

2. Diameter Calculation: The diameter of the binary tree is updated by considering the sum of heights of left and right subtrees for each node.

3. Global Variable Usage: The 'diameter' variable is used as a class member variable to keep track of the overall diameter of the binary tree.

THIS IS AN OPTIMISED WAY OF FINDING THE DIAMETER OF THE ROOT NODE OF THE BINARY TREE

*/

// TIME COMPLEXITY - O(N)
/*
The time complexity of the code is O(N), where N is the number of nodes in the binary tree. This is because each node is visited once, and the findHeight function computes the height of each subtree in a bottom-up manner.
*/

// SPACE COMPLEXITY - O(H)
/*
The space complexity of the code is O(H), where H is the height of the binary tree. This space is used for the recursive call stack during the execution of the findHeight function. In the worst case, for a skewed tree, the height H could be equal to the number of nodes N, resulting in O(N) space complexity.
*/
