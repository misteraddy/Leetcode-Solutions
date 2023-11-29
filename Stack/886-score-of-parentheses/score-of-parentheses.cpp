class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            char bracket = s[i];
            
            if (bracket == '(') {
                st.push(-1);
            } else {
                int val = 0;
                while (!st.empty() && st.top() != -1) {
                    val += st.top();
                    st.pop();
                }

                st.pop(); // Pop the '('
                st.push(val == 0 ? 1 : 2 * val); // If val is 0, it was '()', so push 1; otherwise, double the value.
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};