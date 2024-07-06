/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        
        List<Integer> result = new ArrayList<>() ;

        recursionRight(root,result,0);

        return result ;
    }

    public void recursionRight(TreeNode root,List<Integer> result,int currentLevel)
    {
        if(root == null)
        {
            return ;
        }

        if(result.size() == currentLevel)
        {
            result.add(root.val);
        }

         recursionRight(root.right,result,currentLevel + 1);

         recursionRight(root.left,result,currentLevel + 1);

    }
}