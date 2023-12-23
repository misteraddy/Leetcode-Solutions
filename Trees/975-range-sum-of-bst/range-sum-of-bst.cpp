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
    
    void rangeSumBSTHelper(TreeNode* root,int& sum,int low,int high)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root -> val >= low && root -> val <= high)
        {
            sum = sum + root -> val ;
            
            rangeSumBSTHelper(root -> left,sum,low,high);
            
            rangeSumBSTHelper(root -> right,sum,low,high);
        }
        else if(root -> val < low)
        {
            rangeSumBSTHelper(root -> right , sum , low , high);
        }
        else
        {
            rangeSumBSTHelper(root -> left,sum , low , high);
        }
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        int sum = 0 ;
        
        rangeSumBSTHelper(root,sum,low,high);
         
        return sum ;
        
    }
};

    // APPROACH
    /*
    The approach involves a recursive traversal of the binary search tree (BST).
    For each node, if its value is within the given range [low, high], add its value to the sum.
    Recursively perform the same operation for the left and right subtrees based on the value comparison.
    */
    
    // THINGS YOU LEARNED
    /*
    The code demonstrates a depth-first search (DFS) approach to traverse the BST.
    It efficiently calculates the sum of values within the specified range.
    The recursive helper function explores the tree based on value comparisons to optimize the sum calculation.
    
    normally recursion se bhi ho jaata but usme hum log jyada nodes ko traverse karte hai . isme comparatively kum nodes ko traverse kar rahe hai .
    
    */
    
    // CORNER CASES
    /*
    - The provided code handles the case when the root is NULL, immediately returning in such cases.
    - The comparison conditions ensure that the traversal is directed to the appropriate subtree based on the node's value.
    */
    
    // TIME COMPLEXITY - O(N)
    /*
    The time complexity is O(N), where N is the number of nodes in the binary search tree.
    This is because, in the worst case, the algorithm needs to visit all nodes in the tree.
    */
    
    // SPACE COMPLEXITY - O(H)
    /*
    The space complexity is O(H), where H is the height of the binary search tree.
    This is due to the recursive nature of the solution, and the maximum function call stack size is determined by the height of the tree.
    In the worst case, for a skewed tree, the space complexity approaches O(N), where N is the number of nodes.
    */