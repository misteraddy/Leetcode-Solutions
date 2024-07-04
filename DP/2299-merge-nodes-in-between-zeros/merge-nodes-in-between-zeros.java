/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode mergeNodes(ListNode head) {
        ListNode temp = head;
        ListNode newNode = null;

        while (temp != null) {
            if (temp.val == 0 && temp.next != null) {
                newNode = temp;
                temp = temp.next;
            } else {
                newNode.val = newNode.val + temp.val;
                ListNode delNode = temp;
                newNode.next = temp.next;
                temp = temp.next;
                delNode.next = null;
            }
        }

        return head;
    }
}
