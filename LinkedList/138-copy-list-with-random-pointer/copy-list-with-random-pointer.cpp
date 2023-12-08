/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if (!head) {
            return nullptr; // Handle the case when the original list is empty
        }
        
        unordered_map<Node*, Node*> mpp;
        
        Node* temp = head;
        
        Node* head2 = new Node(temp->val); // Initialize head2 with the first node of the new list
        mpp[temp] = head2; // Map the original node to the corresponding new node
        
        Node* temp2 = head2;
        
        while (temp->next != NULL) {
            temp2->next = new Node(temp->next->val); // Create a new node in the new list
            
            temp = temp->next;
            temp2 = temp2->next;
            
            mpp[temp] = temp2; // Map the original node to the corresponding new node
        }
        
        temp = head;
        temp2 = head2;
        
        while (temp != NULL) {
            temp2->random = (temp->random != NULL) ? mpp[temp->random] : NULL; // Map the random pointer
            
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        return head2;
    }
};









/*


There are several issues in your code that need to be addressed:

Initialization of head2 and temp2: You have declared Node* head2 and Node* temp2 but haven't initialized them properly before using. You should initialize them before using them to avoid undefined behavior.

Loop termination condition in the first while loop: The loop should terminate when temp reaches the end of the original list (temp != NULL), but you are not updating temp2 in the loop, resulting in an infinite loop.

Using temp instead of temp2 in the second while loop: In the second while loop, you are using temp instead of temp2. This will result in an error because temp has already reached the end of the original list.

Not handling the case when the original list is empty (head == NULL): If the original list is empty, your code does not handle this case, and it will result in undefined behavior.

*/