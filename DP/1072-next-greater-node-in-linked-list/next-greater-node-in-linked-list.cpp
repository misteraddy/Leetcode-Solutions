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
    vector<int> nextLargerNodes(ListNode*& head) {

        reverseLL(head);

        vector<int> ans ;

        ListNode* temp = head ;
        
        stack<int> st ;

        while(temp != NULL)
        {
            while(!st.empty() && st.top() <= temp -> val)
            {
                st.pop();
            }

            if(st.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(st.top());
            }

            st.push(temp -> val);
            temp = temp -> next ;
        }

        reverse(ans.begin(),ans.end());

        return ans ;  
    }


    void reverseLL(ListNode*& head) //pass by value bhej rahe the 
    {
        ListNode* prev = NULL ;
        ListNode* current = head ;
        ListNode* next = NULL ;

        while(current != NULL)
        {
            next = current -> next ;
            current -> next = prev ;
            prev = current ;
            current = next ;
        }

        head = prev ;

    }
};

/*
Line 19: Char 9: error: no template named 'Stack'; did you mean 'stack'?
   19 |         Stack<int> st ;
      |         ^~~~~
      |         stack
/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/stl_stack.h:99:11: note: 'stack' declared here
   90 |     class stack



   Line 23: Char 50: error: member reference type 'ListNode *' is a pointer; did you mean to use '->'?
   23 |             while(!st.empty() && st.top() <= temp.val)
      |                                              ~~~~^
      |  



    Line 40: Char 9: error: too many arguments to function call, expected 1, have 2; did you mean '::reverse'?
   40 |         reverse(ans.begin(),ans.end());
      |         ^~~~~~~
      |         ::reverse
/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/stl_algo.h:1145:5: note: '::reverse' declared here
 1136 |     reverse(_BidirectionalIterator __first, _BidirectionalIterator __last)
      |         


*/