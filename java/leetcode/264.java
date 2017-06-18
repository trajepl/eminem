public class Solution {
    public int nthUglyNumber(int n) {
        int[] ugly = new int[n];
        ugly[0] = 1;
        
        int idx2 = 0, idx3 = 0, idx5 = 0;
        int fac2 = 2, fac3 = 3, fac5 = 5;
        
        for(int i = 1; i < n; i++) {
            int min = Math.min(Math.min(fac2, fac3), fac5);
            ugly[i] = min;
            
            if(fac2 == min)
                fac2 = 2 * ugly[++idx2];
            if(fac3 == min)
                fac3 = 3 * ugly[++idx3];
            if(fac5 == min)
                fac5 = 5 * ugly[++idx5];
        }
        return ugly[n-1];
    }
}
