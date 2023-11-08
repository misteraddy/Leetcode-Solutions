/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow = head ;
        ListNode *fast = head ;
        
        while(fast != NULL)
        {
            fast = fast -> next ;
            
            if(fast != NULL)
            {
                fast = fast -> next ;
                slow = slow -> next ;
                
                if(fast == slow)
                {
                    break;
                }
            }
        }
        
        //as specified in the question
        
        if(fast == NULL)
        {
            return NULL;
        }
        
        //slow fir se starting node ko point karne laga through 41 line
        
        slow = head ;
        
        
        //kyunki joh cycle mei joh bacchi nodes hai unka length is equal to
        //the distance of the starting node from the head
        //the derivation is being specified in the notes
        
        while(slow != fast)
        {
            fast = fast -> next ;
            slow = slow -> next ;
        }
        
        return slow;
    }
};