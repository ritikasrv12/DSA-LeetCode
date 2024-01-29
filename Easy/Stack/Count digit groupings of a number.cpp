class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push(x);
        
    }
    
    int pop() {
        if (stack2.empty()) {
            transferElements();
        }
        
        if (!stack2.empty()) {
            int front = stack2.top();
            stack2.pop();
            return front;
        }
        
        return -1; // Assuming -1 as an indicator of an empty queue
    
        
    }
    
    int peek() {
        if (stack2.empty()) {
            transferElements();
        }
        
        if (!stack2.empty()) {
            return stack2.top();
        }
        
        return -1; 
        
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
    }

private:
    std::stack<int> stack1;  // Used for push operation
    std::stack<int> stack2;  // Used for pop and peek operations

    void transferElements() {
        // Transfer elements from stack1 to stack2 to reverse their order
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
