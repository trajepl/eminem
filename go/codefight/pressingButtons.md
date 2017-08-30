Given a string of digits, return all of the possible non-empty letter combinations that the number could represent. The mapping of digits to letters is the same as you would find on a telephone's buttons, as in the example below:



The resulting array should be sorted lexicographically.

## Example

For buttons = "42", the output should be
pressingButtons(buttons) = ["ga", "gb", "gc", "ha", "hb", "hc", "ia", "ib", "ic"].

## Input/Output

- [time limit] 4000ms (go)
- [input] string buttons

A string composed of digits ranging from '2' to '9'.

Guaranteed constraints:
```
0 ≤ buttons.length ≤ 7.
```

- [output] array.string

```go
func pressingButtons(buttons string) []string {
    num2Letters := map[byte][]string{
        '2': []string{"a", "b", "c"},
        '3': []string{"d", "e", "f"},
        '4': []string{"g", "h", "i"},
        '5': []string{"j", "k", "l"},
        '6': []string{"m", "n", "o"},
        '7': []string{"p", "q", "r", "s"},
        '8': []string{"t", "u", "v"},
        '9': []string{"w", "x", "y", "z"},
    }
    letters := []string{}
    for i := 0; i < len(buttons); i++ {
        if len(letters) == 0 {
            letters = append(letters, num2Letters[buttons[i]]...)
        } else {
            var newLetters []string
            for j := 0; j < len(letters); j++ {
                w := letters[j]
                for _, s := range num2Letters[buttons[i]] {
                    newLetters = append(newLetters, w + s)
                }
            }
            letters = newLetters
        }
   }
    return letters
}
```
