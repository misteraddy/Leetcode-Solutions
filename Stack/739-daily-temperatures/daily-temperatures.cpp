class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int,int>> st;
        
        int size = temperatures.size();
        
        vector<int> ans(size);
        
        int value = temperatures[size - 1];
        
        int index = size - 1 ;
        
        pair<int,int> p(value,index);
        
        st.push(p);
        
        for(int i = size - 2 ; i >= 0  ; i--) // Fix: Change the loop condition to i >= 0
        {
            pair <int,int> p ;
            
            p.first = temperatures[i];
            
            p.second = i ;
            
            while(!st.empty() && p.first >= temperatures[st.top().second]) // Fix: Change temp to p.first
            {
                st.pop();
            }
            
            if(!st.empty())
            {
                ans[i] = st.top().second - i ; // Fix: Change st.top() to st.top().second
            }
            
            st.push(p); // Fix: Add the current pair to the stack
        }
        
        return ans ;
    }
};