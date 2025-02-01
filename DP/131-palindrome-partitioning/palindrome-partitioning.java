class Solution {

    private static void recur(String s,int currIndex,List<String> curr,List<List<String>> ans) {

        if(currIndex == s.length()) {
            ans.add(new ArrayList<>(curr));
            return ;
        }

        for(int i = currIndex ; i < s.length() ; i++) {
            if(isPalindrome(s,currIndex,i)) {

                curr.add(s.substring(currIndex,i + 1));

                recur(s,i + 1,curr,ans);

                curr.remove(curr.size() - 1);
            }
        }

    }

    private static boolean isPalindrome(String s,int i,int j) {
        while(i <= j) {
            if(s.charAt(i) != s.charAt(j)) return false;
            i++;
            j--;
        }

        return true;

    }

    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();

        List<String> curr = new ArrayList<>();

        recur(s,0,curr,ans);

        return ans;
    }
}