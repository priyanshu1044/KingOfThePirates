// space complexity: O(1)

class MinStack {
public:
    stack <long long >s;
    long long  min_element;

    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            min_element = val;
        }
        else if(val>=min_element){
            s.push(val);
        }
        else if(val<min_element){
            long long temp=val;           // 2*val - min_element (overflow condition)
            temp=temp*2;
            s.push(temp - min_element);
            min_element = val;
        }
    }
    
    void pop() {
        if(s.empty()){
            return ;
        }
        else{
            if(s.top()>=min_element){
                s.pop();
            }
            else if(s.top()<min_element){
                min_element = 2*min_element - s.top();
                s.pop();
            }
        }
    }
    
    int top() {
        if(s.empty()){
            return -1;
        }
        else{
            if(s.top()>=min_element){
                return s.top();

            }
            else if(s.top()<min_element){
                return min_element;
            }
        }
        return -1;
    }
    
    int getMin() {
        return min_element;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Space complexity: O(n)

class MinStack {
public:
    stack <int>s;
    stack <int>support_stack;
    MinStack() {
       
    }
    
    void push(int val) {
        if(support_stack.empty() || val <= support_stack.top() ){
            support_stack.push(val);
        }
        s.push(val);
    }
    
    void pop() {
        if(support_stack.top() == s.top()){
            support_stack.pop();
        }
        s.pop();

    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        if(support_stack.empty()){
            return -1;
        }
        return support_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */