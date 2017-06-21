import java.util.*;

public class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int[] res = new int[n];
        res[0] = 1;
        
        List<Integer> idx = new ArrayList<>();
        List<Integer> fact = new ArrayList<>();
        List<Integer> origin = new ArrayList<>();

        for(int i: primes) {
            fact.add(i);
            origin.add(i);
            idx.add(0);
        }

        for(int i = 1; i < n; i++) {
            int min = minList(fact);
            res[i] = min;
            for(int j = 0; j < fact.size(); j++) {
                System.out.println(fact);
                if(fact.get(j) == min) {
                    idx.set(j, idx.get(j)+1);
                    fact.set(j, origin.get(j) * res[idx.get(j)]);
                }
            }
        }
        return res[n-1];
    }
    
    public int minList(List<Integer> list) {
        int a = list.get(0);
        for(int i = 0; i < list.size(); i++) {
            if(a > list.get(i)) a = list.get(i);
        }
        return a;
    }

    public static void main(String[] args) {
        Solution solu = new Solution();
        int res = solu.nthSuperUglyNumber(4, new int[]{2,3,5});
        System.out.println(res);
    }
}
