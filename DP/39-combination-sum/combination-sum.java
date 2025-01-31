class Solution {

    private static void recur(int[] candidates, int target,List<Integer> curr,List<List<Integer>> ans,int index) {

        if(target == 0) {
            ans.add(new ArrayList<>(curr));
            return ;
        }

        if(target < 0 || index >= candidates.length) return ;

        curr.add(candidates[index]);

        recur(candidates,target - candidates[index] ,curr, ans,index);

        curr.remove(curr.size() - 1);

        recur(candidates,target,curr,ans,index + 1);
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        Arrays.sort(candidates);

        List<Integer> curr = new ArrayList<>();

        List<List<Integer>> ans = new ArrayList<>();

        recur(candidates,target,curr,ans,0);

        return ans ;
    }
}