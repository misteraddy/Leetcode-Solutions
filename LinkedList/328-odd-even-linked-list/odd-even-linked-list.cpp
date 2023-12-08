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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* headOdd = head;
        ListNode* headEven = head->next;
        ListNode* temp1 = headOdd;
        ListNode* temp2 = headEven;

        while (temp2 != NULL && temp2->next != NULL) {
            temp1->next = temp2->next;
            temp1 = temp1->next;
            temp2->next = temp1->next;
            temp2 = temp2->next;
        }

        temp1->next = headEven;

        return head;
    }
};


// APPROACH
/*

Initialize pointers for odd and even lists (headOdd and headEven), and temporary pointers (temp1 and temp2) to traverse the lists.

Traverse the original list, linking odd-indexed nodes together and even-indexed nodes together.

After the loop, connect the last node of the odd list with the head of the even list.

Return the head of the odd list.

*/


//ERROR THAT I HAD MADE
/*

    mai iss question ko sahi se read nhhi kiya tha pehle 
    mujhe laga ki isme har node k data section mei random values hongi
*/


//TIME COMPLEXITY - O(N)

//SPACE COMPLEXITY - O(1)