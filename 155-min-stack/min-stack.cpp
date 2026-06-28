class MinStack {
public:
    stack<int> s;
    stack<int> ss;
    MinStack() {
        
    }
    
    void push(int value) {
        if(ss.empty() || value <= ss.top()){
            s.push(value);
            ss.push(value);
        } 
        else {
            s.push(value); 
        }
    }
    
    void pop() {
        if(s.empty()) return;
        
        if(s.top() == ss.top()) {
            s.pop();
            ss.pop();
        }
        else s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ss.top();
    }
};
