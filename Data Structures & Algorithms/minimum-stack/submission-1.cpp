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
