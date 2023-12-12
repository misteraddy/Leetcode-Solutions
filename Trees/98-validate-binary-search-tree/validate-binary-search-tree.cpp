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
    
    bool validateBST(TreeNode* root, long long int lowerBound, long long int upperBound)
    {
        if(root == NULL)
        {
            return true;
        }
        
        bool cond1 = root -> val > lowerBound ;
        
        bool cond2 = root -> val < upperBound ;
        
        bool leftAns = validateBST(root -> left, lowerBound, root->val);
        
        bool rightAns = validateBST(root -> right, root->val, upperBound);
        
        return cond1 && cond2 && leftAns && rightAns;
    }
    
    bool isValidBST(TreeNode* root) {
        long long int lowerBound  = LLONG_MIN;
        long long int upperBound = LLONG_MAX;
        
        return validateBST(root, lowerBound, upperBound);
    }
};


//ERROR THAT I HAD MADE 
/*

parameter mei long long int nhi use kar rahe the int ko use kar rahe the 

i was using lowerbound = INT_MIN

upperbound = INT_MAX 

then jab node value will be equal to INT_MAX or INT_MIN it will 
generate error .

toh us error se bachne k liye hum log lowerBound ko INT_MIN se chotaa number aur upperbound ko INT_MAX se bada number rakhte hai

*/


// APPROACH
    /*
    The approach used here is a recursive depth-first search (DFS) to validate whether a given binary tree is a valid binary search tree (BST) or not. For each node in the tree, we check if it satisfies the BST conditions, which involve comparing the node's value with an upper and lower bound. We update these bounds as we traverse the tree recursively.
    */

    // THINGS YOU LEARNED
    /*
    - Recursive depth-first search can be employed to traverse a binary tree and validate certain conditions at each node.
    - Usage of long long int for representing the bounds to prevent overflow issues with extreme integer values.
    - Conditions for a valid BST involve checking that the value of each node lies within the specified bounds.
    */

    // CORNER CASES
    /*
    - The usage of long long int for bounds helps handle extreme values without causing overflow issues.
    - Corner cases include scenarios where the tree is empty (root is NULL) which is handled appropriately.
    */

    // TIME COMPLEXITY - O(N)
    /*
    The time complexity is O(N), where N is the number of nodes in the binary tree. In the worst case, we need to visit each node once to validate the BST conditions.
    */

    // SPACE COMPLEXITY - O(H)
    /*
    The space complexity is O(H), where H is the height of the binary tree. This is due to the recursive call stack. In the worst case, for a skewed tree, the space complexity approaches O(N), but for a balanced tree, it is O(log N).
    */
