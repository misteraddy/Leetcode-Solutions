class Solution {
public:
    bool isValid(string s) {
        
        if(s[0] != 'a')
        {
            return false ;
        }
        
        stack < char > st ;
        
        char ch ;
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            ch = s[i];
            
            if(ch == 'a')
            {
                st.push(ch);
            }
            else if(!st.empty())
            {
                if(ch == 'b')
                {
                    st.push(ch);
                }
                else
                {
                    //ch == 'c'
                    if(!st.empty() && st.top() == 'b')
                    {
                        st.pop();
                        
                        if(!st.empty() && st.top() == 'a')
                        {
                            st.pop();
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false ;
                    }
                    
                }
            }
        }
        
        if(st.empty())
        {
            return true ;
        }
        
        
        return false ;
        
    }
};