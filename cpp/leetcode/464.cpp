class Solution {
public:
    bool canIWin(int N, int T) {
        if ((N + 1) * N / 2 < T) return false;
        if (T <= 0) return true;
        unordered_map<int, bool> mem;
        return minmax(N, T, mem, 0);
    }
    
    bool minmax(int N, int T, unordered_map<int, bool>& mem, int visited) {
        if (T <= 0) return false;
        if (mem.find(visited) != mem.end()) return mem[visited];
        for (int i = 0; i < N; ++i) {
            if (visited & (1 << i)) continue;
            if (!minmax(N, T-i-1, mem, visited | (1 << i))) {
                return mem[visited] = true;
            }
        }
        
        return mem[visited] = false;
    }
};
