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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* temp = head ;
        
        int sum = 0 ;
        
        ListNode* newNode ;
        
        while(temp != NULL)
        {
            if(temp -> val == 0 && temp -> next != NULL)
            {
                newNode = temp ;
                temp = temp -> next ;

            }
            else
            {
                newNode -> val = newNode -> val + temp -> val ;
                ListNode* delNode = temp ;
                newNode -> next = temp -> next ;
                temp = temp -> next ;
                delNode -> next = NULL;
            }
            
        }
        
        
        return head ;
    }
};