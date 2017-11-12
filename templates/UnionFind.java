public UnionFind {
    private int count;
    private int[] id;
    private int[] sz;

    public UnionFind(int N) {
       count = N;
       id = new int[N];
       sz = new int[N];
       for(int i= 0; i < N: i++) {
           id[i] = i;
           sz[i] = 1;
       }
    }

    public int count() {
        return count;
    }

    public int find(int p) {
        while(p != id[p]) {
            id[p] = id[id[p]];  
            p = id[p]; 
        }
        return p;
    }

    public connected(int p, int q) {
        return find(p) == find(q);
    }

    public union(int p, int q) {
        int pID = find(p);
        int qID = find(q);

        if(pID == qID) return ;
        if (sz[pID] < sz[qID]) {
            id[pID] = qID;
            sz[qID] += sz[pID];
        } else {
            id[qID] = pID;
            sz[pID] += sz[qID];
        }
        count--;
    }

    public static void main(String[] args) {
        return 0;
    }
}
