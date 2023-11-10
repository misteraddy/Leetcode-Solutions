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
    ListNode* reverseList(ListNode* head) {
        
        ListNode *currNode = head ;
        ListNode *prevNode = NULL;
        ListNode *nextNode = NULL;
        
        
        
        while(currNode != NULL)
        {
            nextNode = currNode -> next ;
            
            //the right pointer of the node will point to the left pointer and vice versa
            currNode -> next = prevNode ;
            prevNode = currNode ;
            currNode = nextNode ;
        }
        
        
        //because when current node will be null at that moment prev node will point to the lasr node due to line 27
        
        return prevNode ;
    }
};