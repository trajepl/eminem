class Solution {
    public int[][] reconstructQueue(int[][] people) {
        class People {
            int h;
            int k;
            People(int h, int k) {
                this.h = h; this.k = k;
            }
            public String toString() {
                return this.h + " " + this.k;
            }
        }
        Comparator<People> cmp = new Comparator<People>() {
            public int compare(People p1, People p2)   {
                if(p1.h < p2.h) {
                    return 1;
                } else if(p1.h > p2.h) {
                    return -1;
                } else if(p1.k > p2.k) {
                    return  1;
                } else return -1;
            }
        };    
        
        List<People> list = new ArrayList<>();
        for(int[] person : people) {
            list.add(new People(person[0], person[1]));
        }
        Collections.sort(list, cmp);
        
        for(int i = 0; i < list.size(); i++) {
            int cnt = 0;
            People pi = list.get(i);
            for(int j = 0; j < list.size(); j++) {
                People pj = list.get(j);
                if(cnt == pi.k) {
                    list.remove(i);
                    list.add(j, pi);
                    break;
                } else {
                    if(pi.h <= pj.h) cnt++;
                }
            }
        }
        
        int[][] ret = new int[list.size()][2];
        int i = 0;
        for(People person : list) {
            ret[i][0] = person.h;
            ret[i][1] = person.k;
            i++;
        }
        
        return ret;
    }
}

class Solution {
    public int[][] reconstructQueue(int[][] people) {
        if (people == null || people.length == 0 || people[0].length == 0)
            return new int[0][0];

        Arrays.sort(people, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if (b[0] == a[0]) return a[1] - b[1];
                return b[0] - a[0];
            }
        });

        int n = people.length;
        ArrayList<int[]> tmp = new ArrayList<>();
        for (int i = 0; i < n; i++)
            tmp.add(people[i][1], new int[]{people[i][0], people[i][1]});

        int[][] res = new int[people.length][2];
        int i = 0;
        for (int[] k : tmp) {
            res[i][0] = k[0];
            res[i++][1] = k[1];
        }

        return res;
    }
}
