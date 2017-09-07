class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        if(nums.length < k) return null;
        Map<Integer, Integer> map = new HashMap<>();
        for(int num : nums) {
            if(map.containsKey(num)) {
                map.put(num, map.get(num) + 1);
            } else {
                map.put(num, 1);
            }
        }
        
        
        class Entry {
            int num;
            int freq;
            Entry(int num, int freq) {
                this.num = num; this.freq = freq;
            }
        }
        Comparator<Entry> cmp = new Comparator<Entry>() {
            public int compare(Entry e1, Entry e2) {  
                if(e1.freq < e2.freq) return 1;
                if(e1.freq > e2.freq) return -1;
                else return 0;
            }
        };
        
        Queue<Entry> heap = new PriorityQueue<>(nums.length, cmp);
        for(int key: map.keySet()) {
            heap.offer(new Entry(key, map.get(key)));
        }
        
        List<Integer> ret = new ArrayList<>();
        for(int i = 0; i < k; i++) {
            ret.add(heap.poll().num);
        }
        
        return ret;
    }
}

class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> fmap = new HashMap<>();
        for(int n: nums){
            fmap.put(n, fmap.getOrDefault(n, 0)+1);
        }
        List<Integer>[] arr = new LinkedList[nums.length+1];
        for(Map.Entry<Integer, Integer> e: fmap.entrySet()){
            if(arr[e.getValue()]==null) arr[e.getValue()]=new LinkedList<>();
            arr[e.getValue()].add(e.getKey());
        }
        List<Integer> res = new LinkedList<>();
        for(int i=arr.length-1; i>-1 && k>0; i--){
            if(arr[i]!=null) {
                res.addAll(arr[i]);
                k -= arr[i].size();
            }
        }
        return res;
    }
}
