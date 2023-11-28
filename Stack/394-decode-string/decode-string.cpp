//ERROR THAT I WAS DOING IN THIS PROGRAM
//PEHLE STACK KAR RAHE THE USKE ANDHAR FIR RECURSION
//JAB BHI TUM KUCH STRING SE SUBPART UTHAATE HO VOH CHARACTER EXTRACT KARTE HO
//AGAR STRING MEI SUBPART KO STORE KARNA HAI THEN USE SUBSTR FUNCTION

//MAI MULTI DIGIT WALA CASE BHOOL JAATA HU

//MAI YE BHI GALTI KAR RHA THA KI I WAS SIMPLY IGNORING THE '[' 
//ISKA BHI BAHOT IMPORTANT ROLE HAI CODE MEI

//THEN IN SOME CASES "3[a2[c]]" MEI NESTED CONDITION MEI 
//INSIDE "cc" joh produce hoga usko vapas push kar denge

//stack<char> kar rahe the 
//stack<string> banana

class Solution {
public:
    string decodeString(string s) {
    stack<string> st;            // Use a stack to keep track of characters and intermediate results
    string repeatstring = "";    // To store the characters within a bracket

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == ']') {
            // Pop characters from the stack until an opening bracket '[' is encountered
            while (!st.empty() && st.top() != "[") {
                string top = st.top();
                repeatstring += top;
                st.pop();
            }

            st.pop();   // Pop the '[' from the stack

            string numericTimes = "";
            // Pop digits from the stack to determine the repetition count
            // isdigit(st.top()[0]): This part checks if the first character of the top element of the stack is a digit.
            // The isdigit function is a standard C++ function that returns true if the given character is a decimal digit (0-9).
            
            while (!st.empty() && isdigit(st.top()[0])) {
                numericTimes += st.top();
                st.pop();
            }

            reverse(numericTimes.begin(), numericTimes.end());
            int value = stoi(numericTimes);  // Convert the digit string to an integer

            string decodedValue = "";
            // Repeat the characters within the brackets 'value' times
            while (value--) {
                decodedValue += repeatstring;
            }

            st.push(decodedValue);  // Push the decoded value back onto the stack
            repeatstring = "";      // Reset repeatstring for the next iteration
        } else {
            string temp(1, ch); // iss ch character hai isko string mei convert kar rahe hai . the 1 is the size of the string .
            st.push(temp);  // Push individual characters onto the stack
        }
    }

    string ans;
    // Pop any remaining characters from the stack to get the final decoded string
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;  // Return the final decoded string
}

};
