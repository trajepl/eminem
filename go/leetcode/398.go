import(
    "math/rand"
    "time"
)

type Solution struct {
    num []int
}


func Constructor(nums []int) Solution {
    return Solution{num: nums}
}


func (this *Solution) Pick(target int) int {
    flag := make([]int, 0, 0)
    for i := 0; i < len(this.num); i++ {
        if this.num[i] == target {
            flag = append(flag, i)
        }
    }
    return flag[rand.Intn(len(flag))]
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.Pick(target);
 */