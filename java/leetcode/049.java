public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if(strs == null || strs.length == 0) {
            return new ArrayList<List<String>>();
        }
        
        Map<String, List<String>> map = new HashMap<String, List<String>>();
        
        for(String s : strs) {
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            if(!map.containsKey(String.valueOf(chars))) {
                map.put(String.valueOf(chars), new ArrayList<String>());
            }
            map.get(String.valueOf(chars)).add(s);
        }
        
        return new ArrayList<List<String>>(map.values());
    }
}
