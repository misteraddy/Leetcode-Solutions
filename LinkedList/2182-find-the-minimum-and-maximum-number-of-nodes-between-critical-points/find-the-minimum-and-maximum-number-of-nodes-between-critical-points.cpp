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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Initialize the answer vector with default values indicating no critical points found.
        vector<int> ans{-1, -1};
        
        // Initialize pointers to keep track of the nodes in the linked list.
        ListNode* prev = head;
        if (!prev) {
            // If the linked list is empty, return the default answer.
            return ans;
        }
        
        ListNode* curr = head->next;
        if (!curr) {
            // If there is only one node in the linked list, return the default answer.
            return ans;
        }
        
        ListNode* nxt = head->next->next;
        if (!curr) {
            // If there are only two nodes in the linked list, return the default answer.
            return ans;
        }
        
        // Initialize variables to keep track of critical points and the minimum distance.
        int firstCP = -1;
        int secondCP = -1;
        int mini = INT_MAX;
        int i = 0;
        
        // Traverse the linked list to find critical points and calculate distances.
        while (nxt) {
            // Check if the current node is a critical point.
            bool CP = (curr->val > prev->val && curr->val > nxt->val) || 
                      (curr->val < prev->val && curr->val < nxt->val) ? true : false;
            
            if (CP && firstCP == -1) {
                // If it's the first critical point encountered, set both pointers.
                firstCP = i;
                secondCP = i;
            } else if (CP) {
                // If it's not the first critical point, update the minimum distance.
                mini = min(mini, i - secondCP);
                secondCP = i;
            }
            
            // Move the pointers to the next nodes.
            i++;
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;
        }
        
        // Check if only one critical point was found.
        if (firstCP == secondCP) {
            return ans; // Return the default answer.
        } else {
            // Update the answer vector with the minimum distance and the distance between the critical points.
            ans[0] = mini;
            ans[1] = secondCP - firstCP;
        }
        
        return ans; // Return the final answer vector.
    }
};
