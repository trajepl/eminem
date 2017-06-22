/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public int eraseOverlapIntervals(Interval[] intervals) {
        int res = 0;
        if(intervals.length <= 1) return res;
        class MyComparator implements Comparator<Interval> {
           public int compare(Interval t1, Interval t2) {
               return t1.end - t2.end;
           } 
        }
        Arrays.sort(intervals, new MyComparator());
        
        int endOfFlag = intervals[0].end;
        
        for(int i = 1; i < intervals.length; i++) {
            // System.out.println(intervals[i].start + " " + intervals[i].end);
            if(intervals[i].start >= endOfFlag) {
                endOfFlag = intervals[i].end;
            }
            else res++;
        }
        return res;
    }
}
