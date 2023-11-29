class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        stack<string> st;
        
        int count = 0 ;
        
        int size = logs.size();
        
        for(int i = 0 ; i < size ; i ++)
        {
            string str = logs[i];
            
            if(!st.empty())
            {
                if(str == "../")
                {
                    st.pop();
                }
                else if(str == "./")
                {
                    continue;
                }
                else
                {
                    st.push(str);
                }
            }
            else
            {
                if(str == "./")
                {
                    continue;
                }
                else if(str != "../")
                {
                    st.push(str);
                }
            }
        }
        
        
        while(!st.empty())
        {
            count++;
            st.pop();
        }
        
        
        return count;
    }
};