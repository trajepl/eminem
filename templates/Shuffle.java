import java.util.*;

public class Shuffle {
    int[] nums;
    List<List<Integer>> perm = new ArrayList<>();

    public Shuffle(int[] nums) {
        this.nums = nums;
        permutation(perm, new ArrayList<Integer>(), nums, new boolean[nums.length], 0);
    }

    public void permutation(List<List<Integer>> ret, List<Integer> one, int[]nums, boolean[] flag,int id) {
        if(id == nums.length) {
            ret.add(new ArrayList<>(one));
            return ;
        }

        for(int i = 0; i < nums.length; i++) {
            if(flag[i]) continue;
            flag[i] = true;
            one.add(nums[i]);
            permutation(ret, one, nums, flag, id + 1);
            one.remove((Integer)nums[i]);
            flag[i] = false;
        }
    }

    /* Resets the array to its original configuration and return it. */
    public int[] reset() {
        return this.nums;
    }

    /* Returns a random shuffling of the array. */
    public int[] shuffle() {
        Random rand = new Random();
        int len = this.perm.size();
        List<Integer> obj_ret = this.perm.get(rand.nextInt(len));
        int[] ret = new int[this.nums.length];
        int i = 0;
        for(Integer obj: obj_ret) {
            ret[i++] = (int)obj;
        }
        return ret;
    }

    public int[] shuffle() {
        Random random = new Random();
        if(nums == null) return null;
        int[] a = nums.clone();
        for(int j = 0; j < a.length; j++) {
            int i = random.nextInt(j + 1);
            swap(a, i, j);
        }
        return a;
    }


    public static void print(int[] nums) {
        for(int i : nums) 
            System.out.print(i + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        int[] nums = new int[]{1,2,3,4,5,6};
        Shuffle obj = new Shuffle(nums);
        for(List<Integer> one: obj.perm) {
            System.out.println(one);
        }
        print(obj.shuffle());
        print(obj.reset());
        print(obj.shuffle());
    }
}
