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
    bool hasCycle(ListNode *head) {
        
        ListNode *slow = head ;
        ListNode *fast = head ;
        
        //fast -> next -> next nhi ho sakta
        //kyunki aisa bhi case ho sakta ki ek baar fast = fast -> next  karne k baad hi null 
        //pahuch jaye
        //toh dursi baar shift karne pe error aaa jayegaa
        
        while(fast != NULL)
        {
            fast = fast -> next ;
            
            if(fast != NULL)
            {
                fast = fast -> next ;
                slow = slow -> next ;
                
                if(fast == slow)
                {
                    return true;
                }
            }
            
        }
        
        
        return false;
        
    }
};