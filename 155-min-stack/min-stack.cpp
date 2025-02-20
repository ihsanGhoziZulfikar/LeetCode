typedef long long int ll;
class MinStack {
public:
    stack<pair<ll, ll>> st;
    MinStack() {
    }
    
    void push(ll val) {
        ll current_lowest = !st.empty()? st.top().second : 10000000000;
        ll lowest = min(val, current_lowest); 
        st.push({val,lowest});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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