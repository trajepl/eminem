class Solution {
    public String decodeString(String s) {       
        Stack<String> stack = new Stack<>();
        char[] str = s.toCharArray();
        
        for(int i = 0; i < str.length; i++) {
            // System.out.println(stack);
            if(isNum(str[i])) {
                if(stack.isEmpty())
                    stack.push(str[i] + "");
                else if(isNum(stack.peek().charAt(0))) 
                    stack.push(stack.pop() + str[i]);
                else 
                    stack.push(str[i] + "");
            } else if(str[i] == ']') {
                String tmp = "";
                String ret = "";
                
                while(stack.peek().charAt(0) != '[') {
                    tmp = stack.peek() + tmp;
                    stack.pop();
                }
                stack.pop();
                
                for(int j = 0; j < Integer.parseInt(stack.peek()); j++) 
                    ret += tmp;
                
                stack.pop();
                stack.push(ret);
            } else 
                stack.push(str[i]+"");
        }
        String ret = "";
        while(!stack.isEmpty()) {
            if(isNum(stack.peek().charAt(0))) {
                stack.pop();
                continue;
            }
            ret = stack.pop() + ret;
        }
        return ret;
    }
    
    boolean isNum(char c) {
        return c <= '9' && c >= '0';
    }
}

class Solution {
    public String decodeString(String s) {
        String res = "";
        Stack<Integer> intStack = new Stack<Integer>();
        Stack<String> resStack = new Stack<String>();
        int idx = 0;
        while (idx < s.length()) {
            if (Character.isDigit(s.charAt(idx))) {
                int count = 0;
                while (idx < s.length() && Character.isDigit(s.charAt(idx))) {
                    count = count * 10 + (s.charAt(idx)-'0');
                    idx++;
                }
                intStack.push(count);
            }
            else if (s.charAt(idx) == '[') {
                resStack.push(res);
                res = "";
                idx++;
            }
            else if (s.charAt(idx) == ']') {
                int repeat = intStack.pop();
                StringBuilder sb = new StringBuilder(resStack.pop());
                for (int i = 0; i < repeat; i++) {
                    sb.append(res);
                }
                res = sb.toString();
                idx++;
            }
            else {
                res += s.charAt(idx++);
            }
        }
        return res;
    }
}
