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
    
    ListNode* middlELement(ListNode* head)
    {
        ListNode* slow = head ;
        ListNode* fast = head ;
        
        while(fast != NULL)
        {
            fast = fast -> next ;
            
            if(fast != NULL)
            {
                fast = fast -> next ;
                slow = slow -> next ;
            }
        }
        
        return slow ;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* next = NULL ;
        ListNode* prev = NULL ;
        ListNode* curr = head ;
        
        while(curr != NULL)
        {
            next = curr -> next ;
            curr -> next = prev ;
            prev = curr ;
            curr = next ;
        }
        
        return prev ;
    }
    
    bool checkList(ListNode* head , ListNode* head2)
    {
        ListNode* temp = head ;
        ListNode* temp2 = head2 ;
        
        while(temp != NULL && temp2 != NULL)
        {
            if(temp -> val != temp2 -> val)
            {
                return false ;
            }
            
            temp = temp -> next ;
            temp2 = temp2 -> next ;
        }
        
        return true ;
    }
    
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* head2 = middlELement(head);
        
        head2 = reverse(head2);
        
        bool result = checkList(head,head2);
        
        return result;
        
    }
};