// 32ms topological-sort
public class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] res = new int[numCourses];
        int cnt = 0;
        
        int[] indegree = new int[numCourses];
        int[][] adj = new int[numCourses][numCourses];
        
        for(int[] edge : prerequisites) {
            adj[edge[1]][edge[0]] = 1;
            indegree[edge[0]]++;
        }
        
        Queue<Integer> single = new LinkedList<>();
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0) single.offer(i);
        
        while(!single.isEmpty()) {
            int node = single.poll();
            res[cnt++] = node;
            for(int i = 0; i < numCourses; i++) {
                if(adj[node][i] != 0) {
                    if(--indegree[i] == 0) single.add(i);
                }
            }
        }
        if(cnt == numCourses) return res;
        return new int[0];
    }
}
// 8ms dfs
public class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] rst = new int[numCourses];
        if (numCourses == 0 || prerequisites == null) {
            return rst;
        }
        List<List<Integer>> adjList = new ArrayList<List<Integer>>();
        for (int i = 0; i < numCourses; ++i) {
            adjList.add(new ArrayList<Integer>());
        }
        for (int[] edge : prerequisites) {
            adjList.get(edge[1]).add(edge[0]);
        }
        int[] visited = new int[numCourses];
        List<Integer> items = new ArrayList<Integer>();
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) {
                if (!DFS(i, adjList, visited, items)) {
                    return new int[0];
                }
            }
        }
        Collections.reverse(items);
        for (int i = 0; i < items.size(); ++i) {
            rst[i] = items.get(i);
        }
        return rst;
    }
    private boolean DFS(int node, List<List<Integer>> adjList, int[] visited, List<Integer> list) {
        visited[node] = 1;
        for (int i : adjList.get(node)) {
            if (visited[i] == 0) {
                DFS(i, adjList, visited, list);
            }
            if (visited[i] == 1) {
                return false;
            }
        }
        visited[node] = 2;
        list.add(node);
        return true;
    }
}
