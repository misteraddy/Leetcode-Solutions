class Solution {
    public List<String> validStrings(int n) {
        
        List<String> ans = new ArrayList<>();

        StringFinder(n,0,new StringBuilder(),ans);

        return ans;
    }

    void StringFinder(int n,int i,StringBuilder current,List<String> ans)
    {
        if(i == n)
        {
            ans.add(current.toString());
            return ;
        }

        current.append("1");
        StringFinder(n, i + 1,current,ans);
        current.deleteCharAt(current.length() - 1);

        if(current.length() == 0 || current.charAt(current.length() - 1) != '0')
        {
            current.append("0");
            StringFinder(n, i + 1,current,ans);
            current.deleteCharAt(current.length() - 1);
        }
    }
}