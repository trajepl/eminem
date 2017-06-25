public class Solution {
    public boolean checkPerfectNumber(int num) {
        int sum = 0;
        if(num <= 1) return false;
        
        for(int i = 1; i <= Math.sqrt(num); i++) {
            if(num % i == 0) 
                sum += num / i + i;
        }
        
        return sum == num * 2;
    }
}