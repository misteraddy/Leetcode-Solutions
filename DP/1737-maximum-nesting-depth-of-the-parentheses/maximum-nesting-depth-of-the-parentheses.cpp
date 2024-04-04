class Solution {
public:
    int maxDepth(std::string s) {
        std::stack<char> st;  // Creating a stack to keep track of open parentheses.
        int depth = 0;         // Initializing the depth of nested parentheses.

        // Iterating through each character in the string.
        for (char ch : s) {
            // If the character is an open parenthesis, push it onto the stack.
            if (ch == '(') {
                st.push(ch);
            }
            // If the character is a closing parenthesis,
            // update the depth with the maximum of the current depth and the size of the stack,
            // then pop the corresponding open parenthesis from the stack.
            else if (ch == ')') {
                depth = std::max(depth, static_cast<int>(st.size()));
                st.pop();
            }
        }

        // Return the maximum depth found.
        return depth;
    }
};