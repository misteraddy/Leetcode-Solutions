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
    bool isCompleteTree(TreeNode* root) {
        
        //ye ek flag variable hai jaise hi null dikhegaa toh ye true ho jayega
        
        bool notElement = false ;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* frontElement = q.front() ; q.pop() ;
            
            if(frontElement == NULL)
            {
                notElement = true ;
            }
            else
            {
                if(notElement == true)
                {
                    return false;
                }
                
                q.push(frontElement -> left);
                
                q.push(frontElement -> right);
            }
        }
        
        
        return true ;
        
    }
};


//ERROR THAT I HAD MADE 

/*

parent k children ko push karne se pehle check kar liya kro ki kahi voh null toh nhi hai kyunki uss case mei error aa jaataa hai .

*/

//APPROACH
/*
The approach used here is to perform a level-order traversal of the binary tree using a queue.

During the traversal, we track whether we have encountered any null nodes.
We use the flag variable to keep track that we havent encountered any null .if we encounter then change the value of that variable .

If a null node is encountered after a non-null node, it indicates that the tree is not complete. The algorithm continues the traversal until all nodes are processed or a violation of completeness is found.
*/

//THINGS YOU LEARNED 
/*
1. Level-order traversal is useful for checking the completeness of a binary tree.
2. A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as left as possible.
3. The algorithm uses a queue to process the tree nodes level by level.
*/

//CORNER CASES 
/*
The code handles the corner case where a null node is encountered in the middle of a level, indicating that the tree is not complete.
*/

//TIME COMPLEXITY - O(N)
/*
The algorithm performs a level-order traversal, visiting each node once. Therefore, the time complexity is O(N), where N is the number of nodes in the binary tree.
*/

//SPACE COMPLEXITY - O(W)
/*
The space complexity is O(W), where W is the maximum width of the tree at any level. In the worst case, the queue may contain all nodes at the last level of the tree. In a complete binary tree, the maximum width is typically N/2, where N is the total number of nodes in the tree.
*/
