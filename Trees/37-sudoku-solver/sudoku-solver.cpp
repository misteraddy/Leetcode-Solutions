class Solution {
public:

    bool isValid(vector<vector<char>>& board,int row,int col,int c)
    {
        for(int k = 0 ; k < 9 ; k++)
        {
            if(board[row][k] == c)
            {
                return false;
            }

            if(board[k][col] == c)
            {
                return false;
            }

            if(board[3 * (row/3) + k/3][3 * (col/3) + k%3 ] == c)  //yaha error 
            //bodmas ka dhyaan rakhna
            {
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board)
    {
        for(int i = 0 ; i < board.size() ; i++)
        {
            for(int j = 0 ; j < board[0].size() ; j++)
            {
                if(board[i][j] == '.')
                {
                    for(int c = '1' ; c <= '9' ; c++)   //yaha error kiye the c = 0
                                                    //aur character dalna tha
                    {
                        if(isValid(board,i,j,c))
                        {
                            board[i][j] = c ;

                            if(solve(board))
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bool ans = solve(board);
    }
};

//isme n queens ki tarah har possible postion of numbers nhi naaklte 
//bas ek solution nikaalte hai .