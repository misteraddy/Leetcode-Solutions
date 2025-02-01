class Solution {
    public List<String> letterCombinations(String digits) {
        
        List<String> ans = new ArrayList<>();

        Map<Character,String> mp = new HashMap<>();

        mp.put('2',"abc");
        mp.put('3',"def");
        mp.put('4',"ghi");
        mp.put('5',"jkl");
        mp.put('6',"mno");
        mp.put('7',"pqrs");
        mp.put('8',"tuv");
        mp.put('9',"wxyz");

        int n = digits.length();

        if(n == 0) return ans;

        String str = new String("");

        recur(digits,0,n,str,ans,mp);

        return ans;
    }

    private static void recur(String digits,int currIndex,int n,String str,List<String> ans,Map<Character,String> mp) {

        if(currIndex == n) {
           if(str != "") {
            ans.add(new String(str));
           }

           return ;
        }

        String alp = mp.get(digits.charAt(currIndex));

        for(int i = 0 ; i < alp.length() ; i++) {
            
            str += alp.charAt(i);
            recur(digits,currIndex + 1,n,str,ans,mp);
            str = str.substring(0,str.length() - 1);
        }

    }
}