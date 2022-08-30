class MinStack {
    //main issue is to update the min ele when we pop from stack
    stack<long long> st;
    long long miniele=INT_MAX;
public:
    MinStack() {
        if(!st.empty()){
            st.pop();
        }
    }
    
    void push(int value) {
        long long val=value;
        if(st.empty()){
            st.push(val);
            miniele=val;
        }
        else{
        if(val>=miniele){
            st.push(val);
        }
        else{
            st.push(2*1LL*val-miniele);
            miniele=val;
        }
        }
    }
    
    void pop() {
        if(st.empty())return;
        if(st.top()<miniele){
            miniele=2*1LL*miniele-st.top();
        }
        st.pop();
        
    }
    
    int top() {
        if(st.top()>=miniele){
            return st.top();
        }
       
            return miniele;
        
    }
    
    int getMin() {
        if(st.empty())return -1;
        return miniele;
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