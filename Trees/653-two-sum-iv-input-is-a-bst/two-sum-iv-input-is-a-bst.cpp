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
    
    void findInOrder(TreeNode* root,vector<int>& inorder)
    {
        if(root == NULL)
        {
            return ;
        }
        
        findInOrder(root-> left,inorder);
        
        inorder.push_back(root -> val);
        
        findInOrder(root->right,inorder);
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> inorder;
        
        findInOrder(root,inorder);
        
        int start = 0 ;
        
        int end = inorder.size() - 1 ;
        
        while(start < end)
        {
            int sum = inorder[start] + inorder[end];
            
            if(sum == k)
            {
                return true;
            }
            else if(sum < k)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        
        return false;
    }
};


//ERROR THAT I HAD MADE 
/*

vector int type ka tha aur mai usme hum pura node pass kar rahe the uski vajah se error aa rahi thi .

single element wala test case fhas raha 

[1]
2

start <= end wrong hai    


start < end correct hai .

*/

//APPROACH
/*
The approach used in this code is to perform an in-order traversal of the given binary search tree (BST) to obtain the elements in sorted order.

Once the in-order traversal is complete, the algorithm initializes
two pointers
(`start` and `end`) at the beginning and end of the sorted list, respectively. It then iterates through the sorted list using a two-pointer technique to find if there are two elements that sum up to the target value `k`.

If such elements are found, the function returns true; otherwise, it returns false.
*/

//THINGS YOU LEARNED
/*
1. The code utilizes an in-order traversal to obtain elements of the BST in sorted order.
2. It employs a two-pointer technique to efficiently find a pair of elements with a sum equal to the target value.

3. by refernce use 

4.
*/

//CORNER CASES
/*
1. The code handles the case where the root of the BST is null, returning false in such situations.
*/

//TIME COMPLEXITY - O(N)
/*
The time complexity is O(N), where N is the number of nodes in the binary search tree.

The in-order traversal visits each node once, and the two-pointer technique takes linear time.
*/

//SPACE COMPLEXITY - O(N)
/*
The space complexity is O(N), where N is the number of nodes in the binary search tree. This space is used to store the elements of the BST in sorted order in the `inorder` vector. The space required for recursion in the in-order traversal is also considered.
*/


