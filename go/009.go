func isPalindrome(x int) bool {
    if x < 0 { return false }
    
    ret := 0
    ret_tmp := x
    
    for x != 0 {
        ret = (x % 10) + ret * 10
        x = x / 10
    }
    
    return ret == ret_tmp 
}