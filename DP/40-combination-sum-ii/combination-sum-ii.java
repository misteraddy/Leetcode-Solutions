class Solution {

    private static void recur(int[] candidates,int currIndex,int target,List<Integer> curr,List<List<Integer>> ans) {

        if(target == 0 ) {
            ans.add(new ArrayList<>(curr));
            return ;
        }

        if(target < 0 || candidates.length == currIndex) {
            return ;
        }

        int i = currIndex ;

        curr.add(candidates[currIndex]);

        recur(candidates,currIndex + 1,target - candidates[currIndex],curr,ans);

       while(i < candidates.length && candidates[i] == candidates[currIndex]) {
            i++;
        }

        curr.remove(curr.size() - 1);

        recur(candidates,i,target,curr,ans);
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {

        Arrays.sort(candidates);
        
        List<List<Integer>> ans = new ArrayList<>();

        List<Integer> curr = new ArrayList<>();

        recur(candidates,0,target,curr,ans);

        return ans ;
    }
}