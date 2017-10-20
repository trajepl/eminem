public class Solution {
    public int longestValidParentheses(String s) {
        int maxans = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);

        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if(stack.empty()) {
                    stack.push(i);
                } else {
                    maxans = Math.max(maxans, i - stack.peek());
                }
            }
        }
        return maxans;
    }
}

class Solution {
    public int longestValidParentheses(String s) {
        class NotValidParentheses{
            int idx;
            char chr;
            NotValidParentheses(int idx, char chr) {
                this.idx = idx;
                this.chr = chr;
            }
        }
        Stack<NotValidParentheses> stack = new Stack<>();

        char[] chr = s.toCharArray();
        for(int i = 0; i < chr.length; i++) {
            if(!stack.isEmpty()) {
                NotValidParentheses top = stack.peek();
                if(top.chr == '(' && chr[i] == ')')
                    stack.pop();
                else
                    stack.push(new NotValidParentheses(i, chr[i]));
            } else
                stack.push(new NotValidParentheses(i, chr[i]));
        }

        int right = s.length();
        int max = 0;
        while(!stack.isEmpty()) {
            int left = stack.pop().idx;
            max = Math.max(max, right-left-1);
            right = left;
        }
        return Math.max(max, right);
    }
}
