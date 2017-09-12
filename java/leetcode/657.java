class Solution {
    public boolean judgeCircle(String moves) {
        int[] step = new int[4];

        for(char c: moves.toCharArray()) {
            switch(c) {
                case 'L':
                    step[0]++;
                    break;
                case 'R':
                    step[1]++;
                    break;
                case 'U':
                    step[2]++;
                    break;
                case 'D':
                    step[3]++;
            }
        }
        
        return step[1] == step[0] && step[3] == step[2];
    }
}
