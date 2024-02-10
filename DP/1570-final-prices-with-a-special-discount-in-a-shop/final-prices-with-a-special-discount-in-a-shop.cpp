class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n, 0); 
        stack<int> st;
        st.push(0);

        for(int i=n-1; i>=0; i--){
            while(st.top() > prices[i]){
                st.pop();
            }
            int temp = prices[i] - st.top();
            ans[i] = temp;
            st.push(prices[i]);
        }

        return ans;
    }
};