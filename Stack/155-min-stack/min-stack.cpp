class MinStack {
public:
    
    //creation of the stack using the vector
    
    vector < pair<int,int>> st ;
    
    MinStack() {
        
    }
    
    //the make_pair -> this function creates a pair of object with two element of the same
    //type both initialised to val 
    
    
    
    void push(int val) {
        if(st.empty())
        {
            pair<int,int> p = make_pair(val,val);
            st.push_back(p);
        }
        else
        {
            pair<int,int> p ;
            p.first = val;
            
            //second value is the mininum value
            //till the current element
            
            p.second = min(val,st.back().second);
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */