A cryptarithm is a mathematical puzzle for which the goal is to find the correspondence between letters and digits, such that the given arithmetic equation consisting of letters holds true when the letters are converted to digits.

You have an array of strings ```crypt```, the cryptarithm, and an an array containing the mapping of letters and digits, ```solution```. The array ```crypt``` will contain three non-empty strings that follow the structure: ```[word1, word2, word3]```, which should be interpreted as the ```word1 + word2 = word3``` cryptarithm.

If crypt, when it is decoded by replacing all of the letters in the cryptarithm with digits using the mapping in solution, becomes a valid arithmetic equation containing no numbers with leading zeroes, the answer is true. If it does not become a valid arithmetic solution, the answer is false.

## Example

For ```crypt = ["SEND", "MORE", "MONEY"]``` and
```
solution = [['O', '0'],
            ['M', '1'],
            ['Y', '2'],
            ['E', '5'],
            ['N', '6'],
            ['D', '7'],
            ['R', '8'],
            ['S', '9']]
```
the output should be
```isCryptSolution(crypt, solution) = true.```

When you decrypt "SEND", "MORE", and "MONEY" using the mapping given in crypt, you get 9567 + 1085 = 10652 which is correct and a valid arithmetic equation.

For ```crypt = ["TEN", "TWO", "ONE"]``` and
```
solution = [['O', '1'],
            ['T', '0'],
            ['W', '9'],
            ['E', '5'],
            ['N', '4']]
```	    
the output should be
```isCryptSolution(crypt, solution) = false.```

Even though 054 + 091 = 145, 054 and 091 both contain leading zeroes, meaning that this is not a valid solution.

## Input/Output

- [time limit] 4000ms (go)
- [input] array.string crypt

An array of three non-empty strings containing only uppercase English letters.

Guaranteed constraints:
```
crypt.length = 3,
1 ≤ crypt[i].length ≤ 14.
```

- [input] array.array.char solution

An array consisting of pairs of characters that represent the correspondence between letters and numbers in the cryptarithm. The first character in the pair is an uppercase English letter, and the second one is a digit in the range from 0 to 9.

Guaranteed constraints:
```
solution[i].length = 2,
'A' ≤ solution[i][0] ≤ 'Z',
'0' ≤ solution[i][1] ≤ '9',
solution[i][0] ≠ solution[j][0], i ≠ j,
solution[i][1] ≠ solution[j][1], i ≠ j.
```

It is guaranteed that solution only contains entries for the letters present in crypt and that different letters have different values.

- [output] boolean

Return true if the solution represents the correct solution to the cryptarithm crypt, otherwise return false.

## java solution
```java
boolean isCryptSolution(String[] crypt, char[][] solution) {
    int[] charDir = new int[26];
    for(int i = 0; i < solution.length; i++) {
        charDir[solution[i][0] - 'A'] = solution[i][1] - '0';
    }
    int sum = 0;
    for(int i = 0; i < 3; i++) {
        if(i == 2 && sum == sumStr(crypt[i], charDir)) 
            return true;
        int tmp = sumStr(crypt[i], charDir);
        if(tmp == -1) return false;
        sum += tmp;
    }
    return false;
}

int sumStr(String s, int[] dir) {
    int sum = 0;
    for(char c: s.toCharArray()) {
        sum *= 10;
        sum += dir[c-'A'];
        if(sum == 0){
            if(s.length() == 1) return 0;
            return -1;
        } 
        
    }
    System.out.println(sum + " "+ s);
    return sum;
}
```
