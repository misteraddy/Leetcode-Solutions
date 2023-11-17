//the brute force approach 


class Solution {
public:
    
    // Helper function to build the final simplified path by popping elements from the stack
    void buildAns(stack<string>& st, string& ans) {
        if (st.empty()) {
            return;
        }
        
        
        
        // Pop the top element from the stack and append it to the result string
        string minPath = st.top();
        st.pop();
        
        // Recursive call to continue building the result string
        buildAns(st, ans);
        
        ans += minPath;
    }
    
    // Main function to simplify the given path
    string simplifyPath(string path) {
        int i = 0;
        
        // Stack to keep track of valid path components
        stack<string> st;
    
        // Iterate through the characters in the input path
        while (i < path.size()) {
            int start = i;
            int end = start + 1;
            
            // Find the end of the current path component
            while (end < path.size() && path[end] != '/') {
                ++end;
            }
            
            i = end;
            
            // Extract the current path component
            string str = path.substr(start, end - start);
            
            // Ignore redundant or current directory references
            if (str == "/" || str == "/.") {
                continue;
            }
            
            // Push valid path components onto the stack
            if (str != "/..") {
                st.push(str);
            } 
            // Pop the top element for parent directory references
            else if (!st.empty()) {
                st.pop();
            }
        }
        
        // Initialize the result string with a root path or an empty string if the stack is empty
        string ans = st.empty() ? "/" : "";
        
        // Call the helper function to build the final result string
        buildAns(st, ans);
                //simply agar while(!st.empty()){ 
        
//             ans = ans + st.top();
        
//        } tab ye hotaa emoh/ joh wrong ho jaataaa
        
        return ans;
    }
};
