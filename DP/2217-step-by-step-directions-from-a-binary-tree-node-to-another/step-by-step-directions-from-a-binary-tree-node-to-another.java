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
    TreeNode start = null, end = null;
    Map<TreeNode, TreeNode> parent = new HashMap<>();
    StringBuilder stb = new StringBuilder();

    public String getDirections(TreeNode root, int sv, int dv) {
        
        buildParentMap(root, null, sv, dv);
        TreeNode lca = null;

        
        Set<TreeNode> set = new HashSet<>();
        TreeNode temp = start; TreeNode temp2 = end;
        while(temp != null) {
            set.add(temp);
            temp = parent.get(temp);
        }

        while(temp2 != null) {
            if(set.contains(temp2)) {
                lca = temp2; break;
            }
            temp2 = parent.get(temp2);
        }

        // go to lca from start
        temp = start;
        while(temp != lca) {
            stb.append("U");
            temp = parent.get(temp);
        }

        parent = null;

        // go to dest from lca
        findPath(lca, false, new StringBuilder());

        // combined result
        return stb.toString();
    }

    private void findPath(TreeNode lca, boolean isLeft, StringBuilder str) {
        if(lca == null) return;

        if(isLeft) str.append("L"); else str.append("R");

        if(lca == end) { 
            stb.append(new StringBuilder(str.substring(1))); 
            return; 
        }
        
        findPath(lca.right, false, str);
        findPath(lca.left, true, str);
        str.deleteCharAt(str.length() - 1);
    }

    private void buildParentMap(TreeNode node, TreeNode prev, int sv, int dv) {
        if(node == null) return;

        if(sv == node.val) start = node;
        else if(dv == node.val) end = node;
        parent.put(node, prev);
        buildParentMap(node.left, node, sv, dv); buildParentMap(node.right, node, sv, dv);
    }
}