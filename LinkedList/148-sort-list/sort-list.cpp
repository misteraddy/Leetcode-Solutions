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
    
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        
        if (list2 == nullptr) {
            return list1;
        }
        
        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;
        
        while (list1 && list2) {
            if (list1->val >= list2->val) {
                mptr->next = list2;
                mptr = list2;
                list2 = list2->next;
            } else {
                mptr->next = list1;
                mptr = list1;
                list1 = list1->next;
            }
        }
        
        if (list1) {
            mptr->next = list1;
        }
        
        if (list2) {
            mptr->next = list2;
        }
        
        ans = ans->next;
        
        return ans;
    }
    
    ListNode* sortList(ListNode* head) {
    if (head == 0 || head->next == 0) {
        return head;
    }

    ListNode* mid = findMid(head);
    ListNode* left = head ;
    ListNode* right = mid->next;
    mid->next = nullptr;

    left = sortList(left);
    right = sortList(right);

    return mergeTwoLists(left, right);
}

};
