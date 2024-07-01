class Solution {

    public int DFS(int[][]grid,int i,int j,int m, int n)
    {
        if(i<0||j<0||i>=m||j>=n)
        {
            return 0;
        }
        if(grid[i][j]==0)
            return 0;
        grid[i][j]=0;
        int rect=1;
        rect+=DFS(grid,i-1,j,m,n);
        rect+=DFS(grid,i,j-1,m,n);
        rect+=DFS(grid,i+1,j,m,n);
        rect+=DFS(grid,i,j+1,m,n);

        return rect;

    }
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea=0;
        int m=grid.length;
        int n=grid[0].length;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int rec=DFS(grid,i,j,m,n);
                if(maxArea<rec)
                    maxArea=rec;
            }
        }
        return maxArea;
    }
}