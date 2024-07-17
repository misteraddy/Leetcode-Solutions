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
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        List<TreeNode> ans = new ArrayList<>();
        Set<Integer> todeleteSet = new HashSet<>();

        for (int element : to_delete) {
            todeleteSet.add(element);
        }

        root = delNodesChecker(root, todeleteSet, ans);

        if (root != null) {
            ans.add(root);
        }

        return ans;
    }

    private TreeNode delNodesChecker(TreeNode node, Set<Integer> todeleteSet, List<TreeNode> ans) {
        if (node == null) {
            return null;
        }

        node.left = delNodesChecker(node.left, todeleteSet, ans);
        node.right = delNodesChecker(node.right, todeleteSet, ans);

        if (todeleteSet.contains(node.val)) {
            if (node.left != null) {
                ans.add(node.left);
            }
            if (node.right != null) {
                ans.add(node.right);
            }
            return null;
        }

        return node;
    }
}
