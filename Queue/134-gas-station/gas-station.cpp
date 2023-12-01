class Solution {
    
    /*
Intuition
We have to find a particular position such that if we started from that position, we can cover all the gas stations with enough amount of fuel.
Suppose there are two gas stations A and B, if A can reach B, then all the stations in between can also reach B. Also if we consider that A cannot reach B, and B is the first station where A cannot reach, then there are chances that any stations in between A and B can also never reach B as there will not be enough gas available. So we need to consider starting from the gas station after B.
Also if the gas we used to cover all the stations is greater than the cost of gas we paid, then we are surely having a station that will satisfy our condition.

*/
    
    
    //ISS QUESTION KI DIKKAT YE HAI KI TUMHE INTUITION NHI DEVELOP HOGI KI
    //ISME QUEUE USE HOGA
    
    //ERROR JOH MAI KAR RAHA THA
    //deficit mei add hi nhi kar rha tha mai 
    //then balance - deficit check karna tha ki 0 se bada hai yaa nhi
    //agar hai toh start return karo nhi toh -1
    
    //TIME CCMPLEXITY - O(N)
    
    //SPACE COMPLEXITY - O(1)
    
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    // Get the size of the gas vector (assuming gas and cost vectors have the same size)
    int n = gas.size();
    
    // Initialize variables to track the deficit, balance, and starting index
    int deficit = 0;
    int balance = 0;
    int start = 0;
    
    // Iterate through each gas station
    for(int i = 0 ; i < n ; i++) {
        // Update the balance by adding gas and subtracting cost for the current station
        balance = balance + gas[i] - cost[i];
        
        // If the balance becomes negative, indicating insufficient gas to reach the current station
        if(balance < 0) {
            // Update the deficit to store the absolute value of the current balance
            deficit += abs(balance);
            
            // Update the starting index to the next station
            start = i + 1;
            
            // Reset the balance to zero as starting from the current station is not feasible
            balance = 0;
        }
    }
    
    // Check if it is possible to complete the circuit
    if((balance - deficit) >= 0 ) {
        // If the overall balance (accounting for deficit) is non-negative, return the starting index
        return start;
    }
    else {
        // If not, return -1 indicating that it's not possible to complete the circuit
        return -1;
    }
}
};