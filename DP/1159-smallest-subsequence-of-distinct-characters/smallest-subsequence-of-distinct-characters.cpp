class Solution {
public:
    string smallestSubsequence(string s) {

        int n = s.size() ;

        stack<char> st ;  //<int> kiya tha maine
        
        vector<bool> taken(26,false);

        vector<int> lastIndex(26,-1);  //vector by default 0 se initialise hota hai

        for(int i = 0 ; i < n ; i++)
        {
            lastIndex[s[i] - 'a'] = i ;
        }

        for(int i = 0 ; i < n ; i++)
        {
            char ch = s[i];

            int idx = ch - 'a';

            if(taken[idx] == true)
            {
                continue;
            }
                                                            //idx likh raha tha
            while(!st.empty() && st.top() > ch && lastIndex[st.top() - 'a'] > i) //yaha galti kiya
            {
                taken[st.top() - 'a'] = false ;
                st.pop();
            }

            st.push(ch);
            taken[idx] = true;  

        }


        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans ;
    }
};