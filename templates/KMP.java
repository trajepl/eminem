public class KMP {
    public int[] computePrefix(String s) {
        int len = s.length();
        int[] ret = new int[len];
        int flag = 0;

        ret[0] = 0;
        for(int i = 1; i < len; i++) {
            while(flag > 0 && s.charAt(i) != s.charAt(flag))
                flag = ret[flag-1];
            if(s.charAt(i) == s.charAt(flag))
                flag ++;

            ret[i] = flag;
        }
        return ret;
    }

    public boolean kmpMatcher(String s, String k) {
        int[] next = computePrefix(k);
        for(int i: next) System.out.printf("%d ", i);

        int len_s = s.length(), len_k = k.length();
        int idk = 0;

        for(int i = 0; i < len_s; i++) {
            while(idk > 0 && s.charAt(i) != k.charAt(idk)) {
                idk = next[idk-1];
            }
            if(k.charAt(idk) == s.charAt(i)) idk++;
            if(idk == len_k) {
                System.out.printf("Pattern occurs with shift %d ", i-idk+1);
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        KMP kmp = new KMP();
        String k = "babc";
        String s = "abababc";
        System.out.println(kmp.kmpMatcher(s, k));
    }
}
