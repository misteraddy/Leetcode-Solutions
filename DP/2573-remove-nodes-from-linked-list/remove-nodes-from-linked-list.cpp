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
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        vector<int> arr;

        while(temp != NULL) {
            int element = temp->val;
            arr.push_back(element);
            temp = temp->next;
        }

        for(int i = 0 ; i < arr.size() ; i++) {
            while(!st.empty() && st.top() < arr[i]) {
                st.pop();
            }
            st.push(arr[i]);
        }

        ListNode dummyNode;
        dummyNode.val = (-1);

        while(!st.empty()) {
            int val = st.top(); 
            st.pop();
            ListNode* newNode = new ListNode(val); // Allocate memory dynamically
            newNode->next = dummyNode.next;
            dummyNode.next = newNode;
        }

        return dummyNode.next;
    }
};

//Error
/*

Line 38: Char 19: error: cannot initialize a variable of type 'ListNode *' with an rvalue of type 'int'
   38 |         ListNode* dummyNode(-1);
      |                   ^         ~~

    dummyNode aise nhi inititalise karna kabhi - ListNode* dummyNode(-1) ;  or ListNode dummy(-1) ;

    ListNode* dummyNode  ;

    dummyNode -> val = (-1);  this is also wrong


    agar karna bhi toh heap mei memory banana 
    ListNode* dummyNode = new ListNode(-1);
    
    aur fir delete kar dena 

*/