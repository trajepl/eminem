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
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        int len = intervals.size();
        List<Interval> ret = new ArrayList<>();
        if(len == 0) {
            ret.add(newInterval);
            return ret;
        }
        
        boolean flag = true;
        for(int i = 0; i < len; i++) {
            if(intervals.get(i).start > newInterval.start) {
                intervals.add(i, newInterval);
                flag = false;
                break;
            }
        }
        if(flag) {
            intervals.add(newInterval);
        }
        
        
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