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
    
    int getLength(ListNode* head)
    {
        ListNode* temp = head ;
        
        int count = 0 ;
        
        while(temp != NULL)
        {
            temp = temp -> next ;
            count++;
        }
        
        return count;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    int length = getLength(head);

    ListNode* temp = head;

    // Handle the case where the node to be removed is the head
    if (length == n) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    int remove = length - n - 1;

    while (temp != NULL && remove > 0) {
        temp = temp->next;
        remove--;
    }

    // Check if temp->next is not null before accessing temp->next->next
    if (temp != NULL && temp->next != NULL) {
        ListNode* nodeToRemove = temp->next;
        temp->next = temp->next->next;
        delete nodeToRemove; // Free the memory of the removed node
    }

    return head;
}
};