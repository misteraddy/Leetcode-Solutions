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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* tempA = headA ;
        ListNode* tempB = headB ;
        
        while(tempA && tempB)
        {
            tempA = tempA -> next ;
            tempB = tempB -> next ;
        }
        
        //if the no. of nodes of A is less than it will reach the last node at the end
        
        if(tempA == 0)
        {
            //B is the bigger LL
            
            int blen = 0 ;
            
            while(tempB)
            {
                blen ++ ;
                tempB = tempB -> next ;
            }
            
            while(blen)
            {
                blen -- ;
                headB = headB -> next ;
            }
        }
        else
        {
            //A is the bigger LL
            
            int alen = 0 ;
            
            while(tempA)
            {
                alen ++ ;
                tempA = tempA -> next ;
            }
            
            while(alen)
            {
                alen -- ;
                headA = headA -> next ;
            }
        }
        
        
        while(headA != headB)
        {
            headA = headA -> next;
            headB = headB -> next;
        }
        
        
        return headA ;
        
    }
};