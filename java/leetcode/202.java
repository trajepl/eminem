public class Solution {
    public boolean isHappy(int n) {
        Set<Integer> set = new HashSet<>();
        int first = speSum(n);
        
        while(!set.contains(first)) {
            set.add(first);
            first = speSum(first);
            if(first == 1) return true;
        }
        return false;
    }
    
    public int speSum(int n) {
        int sum = 0;
        while(n != 0) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }
}


public class Solution {
    public boolean isHappy(int n) {
    if (n <= 0) return false;

    while (n >= 10) {
        int sum = 0;
        while (n != 0) {
            sum += (n%10)*(n%10);
            n /= 10;
        }
        n = sum;
    }
    return n == 1 || n == 7;
    }
}
