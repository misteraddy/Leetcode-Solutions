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
    
    void getInorder(TreeNode* root,vector<int>& inorder)
    {
        if(root == NULL)
        {
            return ;
        }
        
        getInorder(root -> left,inorder);
        
        inorder.push_back(root -> val);
        
        getInorder(root -> right,inorder);
    }
    
    TreeNode* createBalancedBST(vector<int>& inorder,int inorderStart,int inorderEnd) {
        
        if(inorderStart > inorderEnd)
        {
            return NULL;
        }
        
        int mid = (inorderStart + inorderEnd) / 2 ;
        
        int element = inorder[mid];
        
        TreeNode* root = new TreeNode(element);
        
        root -> left = createBalancedBST(inorder,inorderStart,mid - 1);
        
        root -> right = createBalancedBST(inorder,mid + 1,inorderEnd);
        
        return root ;
        
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> inorder;
        
        getInorder(root,inorder);
        
        int inorderStart = 0 ;
        
        int inorderEnd = inorder.size() - 1 ;
        
        TreeNode* resultNode = createBalancedBST(inorder,inorderStart,inorderEnd);
        
        return resultNode ;
    }
};

// APPROACH
/*
   The approach involves performing an in-order traversal of the given binary search tree (BST)
   to obtain the elements in sorted order. Then, a balanced BST is created using the sorted elements
   to ensure the tree is height-balanced.
*/

// THINGS YOU LEARNED
/*
   1. In-order traversal of a BST results in elements sorted in ascending order.
   2. The process of creating a balanced BST involves recursively selecting the middle element
      as the root and constructing the left and right subtrees similarly.
*/

// CORNER CASES
/*
   1. The case where the original BST is empty (root is NULL) is handled by returning NULL
      in the `getInorder` and `createBalancedBST` functions.
   2. The case where the range `inorderStart` is greater than `inorderEnd` is checked to return NULL
      in the `createBalancedBST` function, indicating an empty subtree.
*/

// TIME COMPLEXITY - O(N)
/*
   The in-order traversal takes O(N) time, where N is the number of nodes in the original BST.
   Creating the balanced BST also takes O(N) time since each node is visited once.
   Therefore, the overall time complexity is O(N).
*/

// SPACE COMPLEXITY - O(N)
/*
   The space complexity is O(N) due to the additional space required for the `inorder` vector
   to store the in-order traversal of the original BST.
   The recursive calls for creating the balanced BST also contribute to the space complexity.
   Therefore, the overall space complexity is O(N).
*/
