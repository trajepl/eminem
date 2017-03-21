public class Solution {

     public List<String> generateParenthesis(int n) {

        List<String> list = new ArrayList<String>();

        backtrack(list, "", 0, 0, n);

        return list;

    }

    

    public void backtrack(List<String> list, String str, int open, int close, int max){

        

        if(str.length() == max*2){

            list.add(str);

            return;

        }

        

        if(open < max)

            backtrack(list, str+"(", open+1, close, max);

        if(close < open)

            backtrack(list, str+")", open, close+1, max);

    }

}

public class Solution {

    private String s="(";

    public List<String> generateParenthesis(int n) {

        List<String> res = new ArrayList<>();

        dfs(n, res, 1);

        return res;

    }



    private void dfs(int n, List<String> res, int flag) {

        if(n == 0) {

            res.add(new String(s));

            return ;

        }



        for(int i = 0; i < 2; i++) {

            if(flag == 0) {s += "("; flag++; i = 2;}

            else if(flag == n) {s += ")"; flag--; n--; i = 2;}

            else if(i == 0) {s += "("; flag++;}

            else {s += ")"; flag--; n--;}

            // System.out.println("before " + s);

            dfs(n, res, flag);



            String c = s.substring(s.length() - 1, s.length());

            s = s.substring(0, s.length()-1);

            // System.out.println("after " + s);

            if(c.equals(")")) {n++; flag++;}

            else flag--;



        }

    }

}
