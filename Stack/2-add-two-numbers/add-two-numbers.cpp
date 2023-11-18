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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to simplify the code.
        // The actual result will be stored starting from the next of this dummy node.
        ListNode* ans = new ListNode(-1);
        // Iterator to traverse the result list and construct it.
        ListNode* it = ans;
        
        // Initialize carry to 0.
        int carry = 0;
        
        // Loop through the lists until both lists are traversed and there is no carry left.
        while (l1 || l2 || carry) {
            // Extract values from the current nodes of l1 and l2.
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            
            // Calculate the sum, including the carry from the previous operation.
            int sum = a + b + carry;
            
            // Update carry for the next calculation.
            carry = sum / 10;
            
            // Extract the digit to be stored in the result list.
            int temp = sum % 10;
            
            // Create a new node for the result list with the calculated digit.
            ListNode* newNode = new ListNode(temp);
            
            // Connect the new node to the result list.
            it->next = newNode;
            
            // Move the iterator to the next node in the result list.
            it = it->next;
            
            // Move to the next nodes in l1 and l2 if they exist.
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        
        // Extract the actual result list starting from the next of the dummy node.
        ListNode* result = ans->next;
        
        // Free the memory allocated for the dummy node.
        delete(ans);
        
        // Return the result list.
        return result;
    }
};
