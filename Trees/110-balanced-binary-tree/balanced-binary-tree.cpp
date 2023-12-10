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
    
    bool isbalanced = true ;
    
    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0 ;
        }
        
        int lh = height(root -> left);
        
        int rh = height(root -> right);
        
        
        if(isbalanced && abs(lh - rh) > 1)
        {
            isbalanced = false ;
        }
        
        return max(lh,rh) + 1 ;
    }
    
    bool isBalanced(TreeNode* root) {
        
        height (root);
        return isbalanced;
    }
};

//ERROR THAT I HAD MADE
/*

int ka return type

*/

//APPROACH
/*
The program uses a recursive approach to calculate the height of the left and right subtrees for each node.
While calculating the height, it checks at each node whether the tree is still balanced.
The balancing condition is based on the absolute difference of heights being less than or equal to 1.
The final result is obtained by calling the isBalanced function, which returns whether the entire tree is balanced or not.

*/

//THINGS YOU LEARNED 
/*

space complexity in binary tree is O(h).

*/

//TIME COMPLEXITY - O(N) //kyunki har element pe ek baar jaroor jaa rahe hai .

//SPACE COMPLEXITY - O(N)

// The space complexity is O(h) where h is the height of the binary tree. This is due to the recursive calls on the stack. In the worst case, when the tree is skewed, the space complexity approaches O(n).