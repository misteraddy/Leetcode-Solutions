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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == 0)
        {
            return list2;
        }
        
        if(list2 == 0)
        {
            return list1;
        }
        
        //the dummy node is initialised as -1 because in order to handle the edge case
        //when one ofist are null then it will return -1
        
        //Certainly! You can leave the dummy node empty (i.e., without assigning a specific value like -1).
        
        ListNode* ans = new ListNode(-1);
        
        ListNode* mptr = ans ;
        
        while(list1 && list2)
        {
            if(list1 -> val >= list2 -> val)
            {
                mptr -> next = list2;
                mptr = list2;
                list2= list2-> next ;
            }
            else
            {
                mptr -> next = list1;
                mptr = list1;
                list1= list1-> next ;
            }
            
            
        }
        
         if(list1)
            {
                 mptr -> next = list1 ;
            }
        
        
        if(list2)
            {
                mptr -> next = list2 ;
            }
        
        
        //this because the intial node is -1 which is not the part of both the lists .
        
        ans = ans -> next ;
        
        
        return ans ;
        
    }
};