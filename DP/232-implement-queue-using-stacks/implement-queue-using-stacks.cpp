//ERROR THAT I MADE 
//peek element mei pehle saaro ko push kar denge s1 k element s2 k andar
//jabtak s1 empty naa ho jaye
//fir s2 k top element ko return kar denge

//TIME COMPLEXITY -PUSH - O(1)   POP - O(n)   PEEK - O(n)

//SPACE COMPLEXITY -PUSH - O(1)  POP - O(n) PEEK - O(n)


//APPROACH 2 :

//ISME HUM LOG S1 MEI DAALTE HI USKO S2 MEI TRANSFER KAR DETE
//ISKI VAJAH SE 

//TIME COMPLEXITY -PUSH - O(n)   POP - O(1)   PEEK - O(1)

//SPACE COMPLEXITY -PUSH - O(n)  POP - O(1) PEEK - O(1)

class MyQueue {
public:
    
    stack<int> s1;
    
    stack<int> s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        
        int ans = -1;
        
        if(!s2.empty())
        {
            ans = s2.top();
        }
        else
        {
            while(!s1.empty())
            {
                int temp = s1.top() ; s1.pop() ;
                s2.push(temp);
            }
            
            ans = s2.top();
        }
        s2.pop();
        
        return ans;

    }
    
    int peek() {
        
        int ans = -1;
        
            if(!s2.empty())
            {
                ans = s2.top();
            }
            else
            {
                while(!s1.empty())
                {int temp = s1.top() ; s1.pop();
                s2.push(temp);}
                
                ans = s2.top();

            }
            
            return ans;
 
    }
        
    
    
    bool empty() {
        
        return s1.empty() && s2.empty() ;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */