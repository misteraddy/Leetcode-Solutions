class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;  // Stack to keep track of indices of opening parentheses
        st.push(-1);    // Initialize the stack with -1 to handle edge cases
        
        //-1 issilye dala gya hai ki pata chale ki koi valid opening bracket majhood hai ki 
        //hai toh stack empty ho hi nhi saktaaa

        int maxLen = 0;  // Variable to store the maximum valid parentheses length

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (ch == '(') {
                st.push(i);  // Push the index of an opening parenthesis onto the stack
            } else {
                st.pop();  // Pop the index of the matching opening parenthesis

                if (st.empty()) {
                    st.push(i);  // If the stack is empty, push the current index onto the stack
                } else {
                    // Calculate the length of the current valid parentheses substring
                    int len = i - st.top();
                    maxLen = max(len, maxLen);  // Update the maximum length if necessary
                }
            }
        }

        return maxLen;  // Return the overall maximum valid parentheses length
    }
};

// Time Complexity: O(n), where n is the length of the input string 's'.
//   The algorithm iterates through the string once.
// har element k pass bas 2 operation ho rahe hai either push or pop

// Space Complexity: O(n), where n is the length of the input string 's'.
//   The space required by the stack can be at most 'n' in the worst case.
