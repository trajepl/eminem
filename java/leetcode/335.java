public class Solution {
    public boolean isSelfCrossing(int[] x) {
        int len = x.length;
        if(len <=3) return false;
        
        for(int i = 3; i < len; i++) {
            // one
            if(x[i] >= x[i-2] && x[i-1] <= x[i-3]) return true;
            // tow
            if(i >= 4 && x[i-1] == x[i-3] && x[i] + x[i-4] >= x[i-2]) return true;
            // three
            if(i >= 5 && x[i-2] >= x[i-4] && x[i-3] >= x[i-1] && 
                x[i-1] >= x[i-3] - x[i-5] && x[i] >= x[i-2] - x[i-4]) return true;
        }
        return false;
    }
}
