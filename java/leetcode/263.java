ipublic class Solution {
    public boolean isUgly(int num) {
        if(num <= 0) return false;
        if(num == 1) return true;
        if(num == 2 || num == 3 || num == 5) return true;
        
        for(int i = 1; i <= (int)Math.sqrt(num); i++) {
            if(num % i == 0) {
                int fac = num / i;
                if(isSpeFac(i)) return false;
                if(isSpeFac(fac)) return false;
            }
        }
        return true;
    }
    
    public boolean isSpeFac(int i) {
        if(i != 1)
            if(isPrime(i)) {
                if(i != 2 && i != 3 && i != 5) return true;
                else return false;
            } else return false;
            
        return false;
    }
    public boolean isPrime(int num) {
        for(int i = 2; i <= (int)Math.sqrt(num); i++) {
            if(num % i == 0) return false;
        }
        return true;
    }
}

public class Solution {
    public boolean isUgly(int num) {
        if(num==1) return true;
        if(num<=0) return false;
	    while(num%2==0) num=num>>1;
	    while(num%3==0) num=num/3;
	    while(num%5==0) num=num/5;
        return num==1;
    }
}
