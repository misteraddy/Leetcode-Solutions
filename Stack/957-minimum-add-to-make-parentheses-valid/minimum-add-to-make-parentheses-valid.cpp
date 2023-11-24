class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char> st;
        
        int size = s.size();
        
        char ch ;
        
        int count = 0 ;
        
        for(int i = 0 ; i < size ; i++)
        {
            ch = s[i];
            
            if(ch == '(')
            {
                st.push(ch);
            }
            else if(ch == ')')
            {
                if (!st.empty()) {
                    st.pop();
                } else {
                    count++; // unbalanced closing parenthesis
                }
            }
        }
        
        // The remaining elements in the stack are unbalanced opening parenthesis
        count += st.size();
        
        return count ;
    }
};
