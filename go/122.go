package main

import(
    "fmt"
)

func maxProfit(prices []int) int {
    if len(prices) <= 1 {
        return 0
    }

    ret := 0
    large, small := prices[0], prices[0]

    for i := 1; i < len(prices); {
        for i < len(prices) && prices[i] < small {
            small = prices[i]
            i++
        }
        if i < len(prices) {
            large = prices[i]
        } else {break}

        for i < len(prices) && prices[i] >= large {
            large = prices[i]
            i++
        }
        fmt.Printf("%d %d\n", small, large)
        ret += large - small
        if i < len(prices) {
            small = prices[i]
        } else {break}
    }
    return ret
}

func main() {
    ret := maxProfit([]int{7,2,6,4,1,7,9,1})
    fmt.Println(ret)
}
