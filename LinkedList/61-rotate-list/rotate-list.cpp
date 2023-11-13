/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        
        ListNode* temp = head;
        int length = 1;  // Length of the list
        while (temp->next != nullptr) {
            temp = temp->next;
            length++;
        }
        
        // Adjust k to avoid unnecessary rotations
        k = k % length;
        if (k == 0) {
            return head;  // No need to rotate
        }
        
        // Find the new head after rotation
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;  // Set the new tail's next to null
        
        // Connect the old tail to the original head
        temp->next = head;
        
        return newHead;
    }
};
