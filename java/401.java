public class Solution {
    public List<String> readBinaryWatch(int num) {
        List<String> res = new ArrayList<>();
        int[] arr_h = {1, 2, 4, 8}, arr_min = {1, 2, 4, 8, 16, 32};
        for (int i = 0; i <= num; i++) {
            List<Integer> list_h = genDigit(i, arr_h);
            List<Integer> list_min = genDigit(num - i, arr_min);
            for(int num_h : list_h) {
                if(num_h >= 12) continue;
                for(int num_min : list_min) {
                    if(num_min >= 60) continue;
                    res.add(num_h + ":" + (num_min < 10?"0"+num_min : num_min));
                }
            }
        }
        return res;
    }
    private List<Integer> genDigit(int i, int[] nums) {
        List<Integer> res = new ArrayList<>();
        genDigitHelper(nums, i, 0, 0, res);
        return res;
    }

    private void genDigitHelper(int[] nums, int count, int pos, int sum, List<Integer>res) {
        if(count == 0) {
            res.add(sum);
            return ;
        }
        for(int i = pos; i < nums.length; i++) {
            genDigitHelper(nums, count - 1, i+1, sum+nums[i], res);
        }
    }
}


public class Solution {
    public List<String> readBinaryWatch(int num) {
         List<String> times = new ArrayList<>();
        for (int h=0; h<12; h++)
            for (int m=0; m<60; m++)
                if (Integer.bitCount(h * 64 + m) == num)
                    times.add(String.format("%d:%02d", h, m));
        return times;        
    }
}