func isValid(s string) bool {
    m := map[byte]byte {
	   ')': '(',
	   ']': '[',
	   '}': '{',
    }

    if len(s) % 2 != 0 {return false;}
    stack := make([]byte, 0, len(s))

    for i := 0; i < len(s); i++ {
        switch s[i] {
            case '(':
                fallthrough
            case '[':
                fallthrough
            case '{':
                stack = append(stack, s[i])
            default:
                if len(stack) == 0 {
                    return false
                } else {
                    item := stack[len(stack) - 1]
                    stack = stack[:len(stack)-1]
                    if m[s[i]] != item {return false}
                }
        }
    }
    return len(stack) == 0
}
