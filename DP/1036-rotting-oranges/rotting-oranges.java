class Solution {

    int[][] directions = {{1,0},{0,1},{-1,0},{0,-1}};

    public int orangesRotting(int[][] grid) {
        
        int n = grid.length;
        int m = grid[0].length;

        int freshOranges = 0;
        Queue<int[]> q = new LinkedList<>();

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 2) {
                    q.offer(new int[] {i, j});
                } else if(grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        if(freshOranges == 0) return 0;

        int time = -1;

        while(!q.isEmpty()) {

            int size = q.size();
            time++;
            for(int k = 0; k < size; k++) {
                int[] cell = q.poll();
                int i = cell[0];
                int j = cell[1];

                for(int[] dirs : directions) {
                    int rowdash = i + dirs[0];
                    int coldash = j + dirs[1];

                    if(rowdash >= 0 && rowdash < n && coldash >= 0 && coldash < m && grid[rowdash][coldash] == 1) {
                        grid[rowdash][coldash] = 2;
                        freshOranges--;
                        q.offer(new int[] {rowdash, coldash});
                    }
                }
            }
        }

        return freshOranges == 0 ? time : -1;
    }
}