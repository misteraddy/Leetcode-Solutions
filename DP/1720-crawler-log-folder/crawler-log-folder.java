class Solution {
    public int minOperations(String[] logs) {
        Stack st1=new Stack();
        for(int i=0;i<logs.length;i++){
            if(logs[i].equals("../")){
                if(!st1.isEmpty()){
                    st1.pop();
                }
            }
            else if(logs[i].equals("./")){
                //Eat Five Star Do Nothing
            }
            else{
                st1.push(logs[i]);
            }
        }

        return st1.size();
    }
}