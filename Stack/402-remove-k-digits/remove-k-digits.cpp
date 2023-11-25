//ERROR THAT I WAS DOING IN THIS QUESTION 
//next greater aur next smaller nikaal rahe the 
//not handling the '0' case
//not handling when explicitly the number in the increasing order

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int size = num.size();
        

        char ch;

        // Iterate through each digit in the input number
        for (int i = 0; i < size; i++) {
            ch = num[i];
            
            
            //finding the previous smaller element approach is being used
            //joh bhi stack mei element aa rahe hai bade wale uss element se
            //voh peak element kehlaa rahe aur iss question mei
            //k peak element hi nikalna hai

            // Finding the previous smaller element approach is being used
            // Elements in the stack represent a decreasing order

            // While the current element is smaller than the top of the stack
            // and there are still removals (k > 0), pop elements from the stack
            while (!st.empty() && ch < st.top() && k > 0) {
                st.pop();
                k = k - 1;
            }

            // Corrected: Use single quotes to push the character onto the stack
            // Avoiding zeroes to be pushed if the stack is empty
            if (!st.empty() || ch != '0') {
                st.push(ch);
            }
        }

        // Pop remaining elements if necessary
        while (!st.empty() && k--) {
            st.pop();
        }

        // If the stack is empty, return "0"
        if (st.empty()) {
            return "0";
        }
    
         //case when all the elements are arranged in the increasing order 
        //toh uss case mei peak element toh nahi milegaa
        //mountain peak wala element
        //toh simply hum pop karte jaa rahe removing the msd elements
        

        // Pop elements from the stack and store them in the original string
        while (!st.empty()) {
            num[size - 1] = st.top();
            st.pop();
            size = size - 1 ;
        }

        // Corrected: Return the substring from the first non-zero index
        return num.substr(size);
    }
};