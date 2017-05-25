package main

import(
    "fmt"
)

// O(n^4)
func maxProfit1(prices []int) int {
    len_p := len(prices)
    if len_p <= 1 {
        return 0
    }

    dis := make([][]int, len_p, len_p)

    for i := 0; i < len_p-1; i++ {
        dis[i] = make([]int, len_p)
        for j := i; j < len_p; j++ {
            dis[i][j] = prices[j] - prices[i]
            // dis[i] = append(dis[i], prices[j] - prices[i])
        }
    }
    max := 0

    for i := 0; i < len_p-1; i++ {
        for j := i+1; j < len_p; j++ {
            if dis[i][j] > 0 {
                ret := dis[i][j]
                for k := j; k < len_p-1; k++ {
                    for m := k+1; m < len_p; m++ {
                        if dis[k][m] > 0 {
                            if ret + dis[k][m] > max {max = ret + dis[k][m]}
                        }
                    }
                }
            }
        }
    }
    return max
}

// O(n)
func maxProfit2(prices []int) int {
    len_p := len(prices)
    if len_p <= 1 {
        return 0
    }

    lowest, highest := prices[0], prices[len_p - 1]
    min_val, min_val_r := 0, 0
    opt := make([]int, len_p)
    opt_r := make([]int, len_p)

    for i := 1; i < len_p; i++ {
        if prices[i] - lowest > min_val {min_val = prices[i] - lowest}
        if lowest > prices[i] {lowest = prices[i]}
        opt[i] = min_val
    }

    for i := len_p - 2; i >= 0; i-- {
        if highest - prices[i] > min_val_r {min_val_r = highest - prices[i]}
        if highest < prices[i] {highest = prices[i]}
        opt_r[i] = min_val_r
    }

    max := 0
    for i := 0; i < len(opt); i++ {
        if opt[i] + opt_r[i] > max {max = opt[i] + opt_r[i]}
    }
    fmt.Printf("%v %v\n", opt, opt_r)
    return max
}
