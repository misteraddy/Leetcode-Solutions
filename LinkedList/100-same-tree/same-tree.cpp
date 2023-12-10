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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(q != NULL && p != NULL)
        {
            if(q -> val == p -> val)
            {
                return isSameTree(q -> left , p -> left) && isSameTree(q -> right,p-> right);
            }
            else
            {
                return false;
            }
        }
        else if(q == NULL && p == NULL)
        {
            return true ;
        }
       
        return false ;
    }
};


//ERROR THAT I HAD MADE 
/*
    
     isse " . " tum classes k attributes ko access nhi kar sakte error aati hai 
     use " -> ".
     
    solution pehle hi dekh liya tha . galti se.

*/




//APPROACH
/*
The function checks whether the corresponding nodes of both trees are equal and recursively checks the left and right subtrees.

It returns true only if the values of the current nodes are equal and the left and right subtrees are also the same. dono nodes agar NULL ho tab bhi same hi kahi jayengi.

If at any point, a mismatch is detected (either in values or structure), the function returns false.

*/
    
    
    
    //TIME COMPLEXITY - O(n)  //kyunki har element ko ek baar visit jaroor kar rha a hai

    //SPACE COMPLEXITY - O(1)