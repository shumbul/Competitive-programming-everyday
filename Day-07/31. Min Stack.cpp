// Link - https://leetcode.com/problems/min-stack/
// Author - Shumbul Arifa

class MinStack {
    stack<pair<int, int>> st;
public:
    /** initialize your data structure here. */
    MinStack() {
        while (!st.empty())
            st.pop();
    }

    void push(int val) {
        if (st.empty() || st.top().second >= val) {
            st.push(make_pair(val, val));
        }
        else
            st.push(make_pair(val, st.top().second));
    }

    void pop() {
        if (st.empty())
            return;
        st.pop();
    }

    int top() {
        if (st.empty())
            return -1;
        return st.top().first;
    }

    int getMin() {
        if (st.empty())
            return -1;
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