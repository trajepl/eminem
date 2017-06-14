public class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> map = new HashMap<>();
        List<String> res = new ArrayList<>();
        int sum = 2000;

        for(int i = 0; i < list1.length; i++) {
            map.put(list1[i], i);
        } 
        for(int j = 0; j < list2.length; j++) {
            if(map.containsKey(list2[j])) {
                int id = map.get(list2[j]);
                if(sum > id+j) {
                    res.clear();
                    res.add(list1[id]);
                    sum = id + j;
                } else if(sum == id+j) {
                    res.add(list1[id]);
                }
            }
        }
        return res.toArray(new String[res.size()]);
    }
}
