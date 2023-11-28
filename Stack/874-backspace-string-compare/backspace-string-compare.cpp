//ERROR THAT I HAD DONE WHILE SOLVING THE QUESTION  

/*Incorrect usage of strcmp: The strcmp function returns an integer, not a boolean. It returns 0 if the strings are equal. In C++, it's more appropriate to use the == operator for string comparison.


Incorrect comparison inside if statement: Instead of if (strcmp(s_ans, t_ans)), you should use if (s_ans != t_ans) for string comparison.

   if(strcmp(s_ans,t_ans))
        {
            return true;
        }
        
        USING THIS INSTEAD USE THAT IS IN LINE 59

*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;

        // Process string s
        for (char ch : s) {
            if (ch == '#') {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(ch);
            }
        }

        // Build the processed string for s
        string s_ans = "";
        while (!st.empty()) {
            s_ans = st.top() + s_ans;
            st.pop();
        }

        // Process string t
        for (char ch : t) {
            if (ch == '#') {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(ch);
            }
        }

        // Build the processed string for t
        string t_ans = "";
        while (!st.empty()) {
            t_ans = st.top() + t_ans;
            st.pop();
        }

        // Compare the processed strings using ==
        return s_ans == t_ans;
    }
};