class Solution {

    int n = 0 ;

    int[][] directions = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,1},{-1,1},{1,-1}};

    public int shortestPathBinaryMatrix(int[][] grid) {

        int lvl = 1 ;
        
        n = grid.length ;

        if(n == 1) 
        {
            return grid[0][0] == 0 ? 1 : -1 ;
        }

        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1; 
        }

        Queue <int[] > q = new LinkedList<> ();

        q.offer(new int[] {0,0});

        grid[0][0] = 1 ;

        while(!q.isEmpty()) {

            int N = q.size() ;

            while(N-- > 0) {

                int[] ceil = q.poll();

                int row =
                 ceil[0] ;

                int col = ceil[1] ;

                for(int[] dirs : directions ) {

                    int rowdash = row + dirs[0] ;
                    int coldash = col + dirs[1] ;

                    if(rowdash == n - 1 && coldash == n - 1) {
                        return lvl + 1 ;
                    }

                    if(isSafe(rowdash,coldash,grid)  && grid[rowdash][coldash] == 0)
                    {
                        q.offer(new int[] {rowdash,coldash});
                        grid[rowdash][coldash] = 1 ;
                    }
                }
            }

            lvl++;
        }

        return -1 ;
        
    }

     private boolean isSafe(int row, int col, int[][] grid) {
        return row >= 0 && col >= 0 && row < n && col < n && grid[row][col] == 0;
    }
}