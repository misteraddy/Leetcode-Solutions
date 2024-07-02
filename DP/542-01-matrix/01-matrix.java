class Solution {

    int n , m ;

    int[][] directions = {{1,0},{0,1},{-1,0},{0,-1}};

    public int[][] updateMatrix(int[][] mat) {
        
        n = mat.length;
        m = mat[0].length;

        int[][] result = new int[n][m];

        Queue<int[]> q = new LinkedList<>() ;

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(mat[i][j] == 0)
                {
                    result[i][j] = 0 ;
                    q.offer(new int[] {i,j});
                }
                else
                {
                    result[i][j] = -1 ;
                }
            }
        }

        while(!q.isEmpty()) {

            int[] ceil = q.poll() ;
            int i = ceil[0];
            int j = ceil[1];

            for(int[] dirs : directions) {
                int rowdash = i + dirs[0];
                int coldash = j + dirs[1];

                if(rowdash >= 0 && rowdash < n && coldash >= 0 && coldash < m && result[rowdash][coldash] == (-1))
                {
                    result[rowdash][coldash] = result[i][j] + 1 ;
                    q.offer(new int[] {rowdash,coldash});
                }

            }
        }

        return result ;
    }
}