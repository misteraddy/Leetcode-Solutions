class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> ans ;
        
        queue<int> q ;  // | 1,2,3,4,5,6,7,8 |

        for(int i = 1 ; i < 9 ; i++) // error i = 0 kiya tha that's why error
        {
            q.push(i);
        }

        while(!q.empty())
        {
            int front_num = q.front(); q.pop() ;

            if(low <= front_num && front_num <= high)
            {
                ans.push_back(front_num);
            }

            int last_digit = front_num % 10 ;

            if(last_digit + 1 <= 9)  // < 9 is also wrong 
            {
                int num = front_num * 10 + (last_digit + 1) ;  // 12 ----> 123
                q.push(num);
            }
        }

        return ans ;
    }
};

//bfs approach 