package main

import(
    "fmt"
)

func max_int(elm ...int) int{
    max := elm[0]
    for _, item := range elm {
        if item > max {max = item}
    }
    return max
}

func maxProfit(k int, prices []int) int {
    var n int = len(prices)

    if n <= 1 {return 0}
    if k > n / 2 {return fastSolve()}
    global := make([][]int, n)
    local := make([][]int, n)

    for i := 0; i < n; i++ {
        global[i] = make([]int, k+1)
        local[i] = make([]int, k+1)
    }

    for i := 1; i < n; i++{
        diff := prices[i] - prices[i-1]

        for j := 1; j <= k; j++ {
            local[i][j] = max_int(global[i-1][j-1] + max_int(diff, 0), local[i-1][j]+diff)
            global[i][j] = max_int(global[i-1][j], local[i][j])
        }
    }
    fmt.Printf("%v\n%v\n", global, local)
    return global[n-1][k]
}

func fastSolve(prices []int) int {
    max := 0
    for i := 1; i < len(prices); i++ {
        tmp := prices[i] - prices[i-1]
        if tmp > 0 {max += tmp}
    }
    return max
}

func main() {
    ret := maxProfit(2, []int{1,7,4,9,1,5})
    fmt.Println(ret)
}
