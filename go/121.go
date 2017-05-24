package main

import(
    "fmt"
)

func max_ret(elm ...int) int{
    max := elm[0]
    for _, item := range elm {
        if max < item {max = item}
    }
    return max
}

func maxProfit1(prices []int) int {
    if len(prices) <= 1 {
        return 0
    }
    ret := 0
    idx := 0
    min := prices[0]

    for i := 1; i < len(prices); {
        for i < len(prices) && prices[i] > prices[idx] {
            ret = max_ret(ret, prices[i] - min)
            idx = i
            i++
        }
        if i < len(prices) && prices[i] < min {
            min = prices[i]
            idx = i
        }
        i++
    }
    return ret
}


func maxProfit2(prices []int) int {
    if len(prices) <= 1{
        return 0
    }
    var lowbuy int = prices[0]
    var ret int = 0
    for _,v := range(prices){
        if v - lowbuy > ret {
            ret = v - lowbuy
        }
        if v < lowbuy {
            lowbuy = v
        }
    }
    return ret
}
