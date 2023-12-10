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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                
                while (pred->right != NULL && pred->right != curr) {
                    pred = pred->right;
                }
                
                if (pred->right == NULL) {
                    // Establish the threading
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Revert the threading
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};


// ERROR THAT I HAD MADE
/*
There are several issues in the code:
1. The condition `if(root -> left == NULL)` is incorrect. You should check if `curr` is NULL instead of `root`.
2. The loop condition `while(pred -> right != NULL)` might lead to a segmentation fault if `pred` is NULL. You need to ensure that `pred` is not NULL before accessing its `right` pointer.
3. In the return statement, you should return `ans` instead of `root`.
*/

// APPROACH
/*
The code appears to be an implementation of Morris Traversal for in-order traversal of a binary tree. Morris Traversal uses threading to traverse the tree without using additional space. It modifies the tree temporarily to establish a connection between the rightmost node of the left subtree and the current node.

The algorithm involves the following steps:
1. If the current node's left child is NULL, process the current node and move to its right child.
2. If the current node's left child is not NULL, find the predecessor (rightmost node in the left subtree).
   a. If the predecessor's right child is NULL, set it to the current node and move to the left child.
   b. If the predecessor's right child is the current node, revert the changes (set right child to NULL), process the current node, and move to the right child.

Repeat these steps until all nodes are processed.

*/

// THINGS YOU LEARNED
/*
1. Morris Traversal is an in-order tree traversal algorithm that does not use recursion or additional space.
2. Correctly setting and updating the threading between nodes is crucial for the algorithm's success.
3. It's important to handle edge cases, such as checking for NULL pointers to avoid segmentation faults.
*/

// TIME COMPLEXITY - O(N)
// The time complexity is O(N) because each edge is traversed at most twice (once to establish the threading and once to revert it).

// SPACE COMPLEXITY - O(1)
// The space complexity is O(1) as the algorithm uses only a constant amount of extra space for variables.
