//ERROR THAT I WAS DOING WHILE SOLVING THIS QUESTION WAS
//ek baat jaan lo agar likhaa ho in increasing order that means sorting
//aur series of elements ko check karna hai o(n) se less mei than queue will
//do this in less time

//
//pehle toh q mei daalne k baad custom comparator ki help se sort kar raha tha
//aur ans mei push_back kar rha tha isme dekho q.front ki value wali position 
//par place kar rahe hai

class Solution {
public:
    // Function to reveal the cards in increasing order
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // Sort the deck in ascending order
        sort(deck.begin(), deck.end());

        // Initialize a queue to keep track of the indices
        queue<int> q;

        // Populate the queue with initial indices
        for(int i=0; i<deck.size(); i++) 
            q.push(i);

        // Initialize the answer vector
        vector<int> ans(deck.size());

        // Reveal the cards in increasing order
        for(int i : deck) {
            // Place the current card at the front of the revealed positions
            ans[q.front()] = i;
            q.pop();

            // If there are still positions left, move the next position to the back
            if(!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        // Return the final revealed deck
        return ans;
    }
};  

// Time complexity: O(N log N) - Sorting the deck sort stl nlogn leti hai
// Space complexity: O(N) - Additional space used for the queue and answer vector
