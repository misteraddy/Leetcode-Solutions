//the brute force is using 2 for loops nested and time complexity in the case will be O(N^2)



class StockSpanner {
public:
    
    
    
    // Using a stack to keep track of pairs of (price, span) where span is the number of consecutive days the price has been less than or equal to the current price.
    stack<pair<int, int>> st;

    StockSpanner() {
        // Constructor, initializes an empty stack.
    }

    int next(int price) {
        // Function to calculate the span for the given price.

        // Initialize span to 1 (the current day).
        int span = 1;

        // Check the stack for previous prices that are less than or equal to the current price.
        while (!st.empty() && st.top().first <= price) {
            // Accumulate the span for consecutive days with prices less than or equal to the current price.
            span += st.top().second;

            // Pop the pair from the stack as it is no longer needed.
            st.pop();
        }

        // Push the current price and its corresponding span onto the stack.
        st.push({price, span});

        // Return the calculated span for the current price.
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
