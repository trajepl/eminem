public class Solution {
    int res = 0;

    public int countArrangement(int N) {
        dfs(N, N, new boolean[N+1]);
        return res;

    }

    private void dfs(int N, int k, boolean[] visited) {
        if(k == 0) {
            res++; return ;
        }

        for(int i = 1; i <= N; i++) {
            if(visited[i] || i % k != 0 && k % i != 0) continue;

            visited[i] = true;
            dfs(N, k - 1, visited);
            visited[i] = false;
        }
    }
}
