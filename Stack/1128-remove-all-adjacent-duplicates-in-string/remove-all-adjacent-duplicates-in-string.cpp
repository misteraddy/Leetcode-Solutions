class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans = "";

        for (char ch : s) {
            
            //pehle st.empty() naa likhne pe runtime error aa raha tha 
            //because empty stack se top ko access karna iss a error 
            //check the screenshot
            
            if (!st.empty() && ch == st.top()) {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        while (!st.empty()) {
            ans = st.top() + ans; // Append to the front of the string
            st.pop();
        }

        return ans;
    }
};
