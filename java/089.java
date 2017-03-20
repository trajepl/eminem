public class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> res = new ArrayList<>();
        res.add(0);
        for (int i = 0; i < n; i++) {
            int len = res.size();
            while(--len >= 0) {
                int tmp = (int)(res.get(len) + Math.pow(2, i));
                res.add(tmp);
            }
        }
        return res;
    }
}

public class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> result = new LinkedList<>();
        for (int i = 0; i < 1<<n; i++) result.add(i ^ i>>1);
        return result;
    }
}
