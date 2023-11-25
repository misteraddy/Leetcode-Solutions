//ERROR THAT I WAS DOING IN THE CODE

// mei joh hu voh stack k top ko negative hone pe pop karne ka soch rha tha
//but case ulta hai 

//jab current number positive and the top element negative then uss case mei kuch remove nhi hota         <----A1 ( current ass )   (top ass) ------> 

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack <int> st;
        
        vector<int> ans;
        
        int size = asteroids.size();
        
        st.push(asteroids[0]);
        
        for(int i = 1 ; i < size ; i++)
        {
            int num = asteroids[i];
            
            if(num > 0)
            {
                st.push(num);
            }
            //the number is negative 
            else
            {
                //case : 
                //When the num is negative and other is positive
                //CAUTION : st.top() when the stack is empty will produce runtime error
                while(!st.empty() && st.top() > 0 && st.top() < abs(num))
                {
                    st.pop();
                }
                
                //When the current element is equal size 
                if(!st.empty() && st.top() == abs(num))
                {
                    st.pop();
                }
                else if(!st.empty() && st.top() > abs(num))
                {
                    //iss case mei voh number add hi nhi karenge stack mei ignore
                }
                //when the element is negative and absolute value is less
                else
                {
                    st.push(num);
                }
            }  
        }
        
        while(!st.empty())
        {
            int temp = st.top() ; st.pop();
            ans.push_back(temp);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans ;
    }
};