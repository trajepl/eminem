func hammingDistance(x int, y int) int {
    sum := 0

    for x != 0 || y != 0 {
        if x % 2 != y % 2 {
            sum ++
        }
        y = y / 2
        x = x / 2
    }
    return sum
}

