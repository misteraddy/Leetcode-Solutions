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
    
    int getlength(ListNode* head)
    {
        int count = 0 ;
        ListNode *temp = head;
        while(temp != NULL)
        {
            count ++ ;
            temp = temp -> next ;
        }
        
        return count ;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
 
        int len = getlength(head);

        if(k > len)
        {
            return head;
        }
        
        
        ListNode *prevNode = NULL;
        ListNode *currNode = head;
        ListNode *nextNode = currNode -> next;

        int position = 0 ;
        
        
        
        while(position < k)
        {
            nextNode = currNode -> next ;
            currNode -> next = prevNode ;
            prevNode = currNode ;
            currNode = nextNode ;
            position ++ ;
        }
        
        ListNode* recursionKaAns = NULL ;
        
        
        
        
        if(nextNode != NULL)
        {
            
            //agar aur nodes left hai then 
            //recursively call the reverseKGroup function for the remaining portion of the linked               list, storing the result in recursionKaAns, and then connects the current head to the               result of the recursion.
            
            //head of the k sized reversed node group ka face right side hota hai naa reverse linked list k case mei 
            
            recursionKaAns = reverseKGroup(nextNode,k);
            
            //the iss jagah sab error karte hai
            head -> next = recursionKaAns ;
        }
        
        //yaha bhi bahot error ho jaati hai
        
        return prevNode;
    }
};