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
        
        if (head == NULL) {
            return NULL;
        }
        
        Node* temp = head;
        
        // Duplicate each node and insert it between the original nodes
        while (temp != NULL) {
            Node* clonedNode = new Node(temp->val);
            clonedNode->next = temp->next;
            temp->next = clonedNode;
            temp = temp->next->next;
        }
        
        // Assign random links for the cloned nodes
        temp = head;
        while (temp != NULL) {
            if (temp->random != NULL) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        
        // Separate the original and cloned nodes
        Node* newHead = head->next;
        temp = head;
        
        while (temp != NULL) {
            Node* clonedNode = temp->next;
            temp->next = clonedNode->next;
            
            if (clonedNode->next != NULL) {
                clonedNode->next = clonedNode->next->next;
            }
            
            temp = temp->next;
        }
        
        return newHead;
    }
};


//APPROACH

/*

    Clone and Interleave:

    Traverse the original linked list, and for each node encountered:
    Create a new node (clonedNode) with the same value as the original node.
    Insert the clonedNode between the original node and its next node.
    This effectively creates a new linked list where each node in the original list     is followed by its clone.
    
    Assign Random Links for Cloned Nodes:

    Separate Original and Cloned Lists:
    
    Return the Head of Cloned List:

    Memory Cleanup:

*/

//ERROR THAT I HAD MADE 

/*
 
 head = head -> next kar diya tha jiski vajah se 
 ye problem ho rhi thi ki deep copy waala hi remove ho jaa raha tha 
 
 Memory Leak: The code doesn't free the memory of the cloned nodes correctly. After removing the previous nodes in the last loop, the original head node still points to the first cloned node, but the memory of the first cloned node is not freed. This could result in a memory leak.

*/



//TIME COMPLEXITY - O(N)

//SPACE COMPLEXITY - O(1)


/*
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



*/

//TIME COMPLEXITY - O(N)

//SPACE COMPLEXITY - O(N) KYUNKI MAP use kar rahe issiliye

/*


There are several issues in your code that need to be addressed:

Initialization of head2 and temp2: You have declared Node* head2 and Node* temp2 but haven't initialized them properly before using. You should initialize them before using them to avoid undefined behavior.

Loop termination condition in the first while loop: The loop should terminate when temp reaches the end of the original list (temp != NULL), but you are not updating temp2 in the loop, resulting in an infinite loop.

Using temp instead of temp2 in the second while loop: In the second while loop, you are using temp instead of temp2. This will result in an error because temp has already reached the end of the original list.

Not handling the case when the original list is empty (head == NULL): If the original list is empty, your code does not handle this case, and it will result in undefined behavior.

*/