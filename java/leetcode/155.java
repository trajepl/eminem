public class MinStack {
    Stack<Integer> minStack;
    Queue<Integer> minHeap;
    int min;
    /** initialize your data structure here. */
    public MinStack() {
        minStack = new Stack<>();
        min = Integer.MAX_VALUE;
        minHeap = new PriorityQueue<>();
    }
    
    public void push(int x) {
        minHeap.offer(x);
        minStack.push(x);
    }
    
    public void pop() {
        minHeap.poll();
        minStack.pop();
    }
    
    public int top() {
        return minStack.peek();
    }
    
    public int getMin() {
        return minHeap.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
