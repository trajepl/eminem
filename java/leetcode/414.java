public class Solution {
    public int thirdMax(int[] nums) {
        long first = nums[0], second=Long.MIN_VALUE, third=Long.MIN_VALUE;
        for(int num: nums) {
            if(num > first) {
                third = second;
                second = first;
                first = num;
            }
            else if(num < first && num > second) {
                third = second;
                second = num;
            }
            else if(num < second && num > third) third = num;
        }
        if(third != Long.MIN_VALUE) return (int)third;
        else return (int)first;
    }
}
