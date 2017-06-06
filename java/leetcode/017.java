public class Solution {
    String tmp = "";

    public List<String> letterCombinations(String digits) {
        String[] map = {"", "", "abc", "def", 
        "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        List<String> res = new ArrayList<>();

        if(digits.length() == 0) return res;
        backTrack(map, digits, 0, digits.length(), res);
        return res;
    }


    private void backTrack(String[] map, String digits, int blockId, int num, List<String> res) {
        if(num == 0) {
            res.add(new String(tmp));
            return ;
        }
        int id = digits.charAt(blockId)-'0';
        
        for(int i = 0; i < map[id].length(); i++) {
            tmp += map[id].charAt(i);
            backTrack(map, digits, blockId+1, num-1, res);
            tmp = tmp.substring(0, tmp.length()-1);
        }

    }
}
