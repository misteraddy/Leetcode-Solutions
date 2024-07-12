class Solution {
    public int maximumGain(String s, int x, int y) {
        int points = 0;
        Stack<Character> stack = new Stack<>();
        char c1, c2; 
        int max = Math.max(x,y);
        int min = Math.min(x,y);
        if(y>x){
            c1 = 'a';
            c2 = 'b';
        }else{
            c1 = 'b';
            c2 = 'a';
        }

        for(int i=0 ; i<s.length();i++){
            if(stack.isEmpty()){
                stack.push(s.charAt(i));
                continue;
            }
            if(s.charAt(i)==c1 && stack.peek()==c2){
                points +=max;
                stack.pop();
            }else{
                stack.push(s.charAt(i));
            }
        }
        char[] charArr = new char[stack.size()];
        for(int i=stack.size()-1 ; i>=0 ; i--){
            charArr[i]=stack.pop();
        }
        for(int i=0 ; i<charArr.length;i++){
            if(stack.isEmpty()){
                stack.push(charArr[i]);
                continue;
            }
            if(charArr[i]==c2 && stack.peek()==c1){
                points +=min;
                stack.pop();
            }else{
                stack.push(charArr[i]);
            }
        }
        return points;
    }
}