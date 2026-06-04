//We cannot maintain min order inside stack because it would break LIFO and make operations O(n), 
//so we use an auxiliary structure to track minimum in O(1).
class MinStack {
//private data strutures(var)
private:
    stack<int>s;//main stack
    stack<int>m;//min stack
public:
    MinStack() {
        // constructor
    }
    
    void push(int val) {
        s.push(val);

        if(m.empty()||val<=m.top())
            m.push(val);
    }
    
    void pop() {
        if(s.top()==m.top())    
            m.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.top();
    }
};
