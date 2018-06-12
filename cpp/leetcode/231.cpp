class Solution {
public:
    bool isPowerOfTwo(int n) {        
        int bits_cnt = 0;
        while (n != 0) {
            bits_cnt += n & 1;
            if (bits_cnt > 1) return false;
            n = n >> 1;
        }
        return bits_cnt == 1;
    }

    bool isPowerOfTwo1(int n) {
        if (n > 0 && (n & (n-1)) == 0) return true;
        return false;
    }

};
