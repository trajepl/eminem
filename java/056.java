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
    public List<Interval> merge(List<Interval> intervals) {
        if(intervals.size() <= 1) return intervals;
        
        Collections.sort(intervals, new Comparator<Interval>(){
            public int compare(Interval first, Interval sec) {
                if(first.start < sec.start) return -1;
                else if(first.start == sec.start) return 0;
                else return 1;
            }
        });
        
        List<Interval> ret = new ArrayList<>();
        
        for(int i = 0; i < intervals.size(); ) { 
            int start_t = intervals.get(i).start;
            int end_t = intervals.get(i).end;
            i++;
            
            while(i < intervals.size() && end_t >= intervals.get(i).start) {
                if(end_t < intervals.get(i).end)
                end_t = intervals.get(i).end;
                i++;
            }
            ret.add(new Interval(start_t, end_t));
        }
        return ret;
    }
}