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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* slow = head ;
        ListNode* fast = head ;
        
        //slow will move by 1 step
        //fast will move by 2 step 
        //so when the fast reaches the end point
        //as the slow will be at the mid point
        //kyunki half speed se chal rhaa
        
        while(fast != NULL)
        {
            fast = fast -> next ;
            
            if(fast != NULL)
            {
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        
        
        return slow ;
        
    }
};