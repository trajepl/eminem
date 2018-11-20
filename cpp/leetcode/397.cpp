class Solution {
public:
    int integerReplacement(int n) {
        int c = 0;
        long new_n = n;
        while (new_n != 1) {
            if ((new_n & 1) == 0) {
                new_n = new_n >> 1;
            } else if (new_n == 3 || ((new_n >> 1) & 1) == 0) {
                --new_n;
            } else {
                ++new_n;
            }
            ++c;
        }
        return c;
    }
};
