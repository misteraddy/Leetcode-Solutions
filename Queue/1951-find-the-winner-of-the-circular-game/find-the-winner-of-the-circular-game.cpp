//ERROR THAT I WAS MAKING WHILE SOLVING THIS 

/*
The Time Limit Exceeded (TLE) issue in your code is likely due to the inefficient way you are handling the elimination process in the while loop. The loop seems to be stuck, and the value of i is not being incremented correctly.


 while(dq.size() != 1)
        {
            int temp = dq.front() ; dq.pop_front();
            
            int i = 1 ;
            
            if(i == k)
            {
                i = 1 ;
                continue;
            }
            
            i++;
            
            dq.push_back(temp);
        }

    APPROACH
    1)initialise a queue from 1 to n
    2)while q has more than 1 number
    3)for k-1 times pop front and add at the back
    4)pop the last element 
    5)return first and only element of the queue

*/


class Solution {
public:
    int findTheWinner(int n, int k) {
        
        // Create a deque to represent the circle of people.
        std::deque<int> dq;
        
        // Initialize the deque with values from 1 to n.
        for(int i = 1; i <= n; i++) {
            dq.push_back(i);
        }
        
        //  the elimination process jab tak ek hi aadmi naa reh jaye.
        while(dq.size() != 1) {
            // Retrieve the front person from the deque.
            int temp = dq.front(); 
            dq.pop_front();
            
            int i = 1;

            // Skip k-1 people and eliminate the k-th person.
            while (i != k) {
                // Move the skipped person to the back of the deque.
                dq.push_back(temp);
                // Retrieve the next person from the front.
                temp = dq.front();
                // Remove the front person from the deque.
                dq.pop_front();
                // Increment the counter.
                i++;
            }
        }
        
        // Return the remaining person who is the winner.
        return dq.front();
    }
};

//time complexity in this question - O(N * k)  
//outer loop is running n times while the inner loop is running k times it is skipping the k-1 element and then skip the kth element .

//space complexity in this question - O(1) BECOZ NO EXTRA SPACE IS USED .
