public class Solution {
    public String reverseStr(String s, int k) {
        char[] chars = s.toCharArray();
        for(int i = 0; i < chars.length; i += 2 * k){
            int j = Math.min(i + k - 1, chars.length - 1);
            reverse(chars, i, j);
        }
        return new String(chars);
    }
    
    public void reverse(char[] array, int start, int end){
        while(start < end){
            char temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            start++;
            end--;
        }
    }
}

public class Solution {
    public String reverseStr(String s, int k) {
        Stack<Character> stack = new Stack<>();
        StringBuilder sb = new StringBuilder();
        boolean flag = false;
        int id = 0;
        for(char c: s.toCharArray()) {
            if(flag) {
                sb.append(c); id--;
                if(id == 0) flag = false;
            } else {
                stack.push(c);
                id++;
            }
            if(id == k) {
                flag = true;
                while(!stack.isEmpty()) {
                    sb.append(stack.pop());
                }
            }
        }
        if(!flag) {
            while(!stack.isEmpty()) {
                sb.append(stack.pop());
            }
        }
        return sb.toString();
    }
}
