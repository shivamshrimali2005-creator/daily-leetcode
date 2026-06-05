class CustomStack {
    stack<int> st;
    int size;
public:
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(st.size() == size) return;
        else{
            st.push(x);
        }
    }
    
    int pop() {
        if(st.empty()) return -1;
        else{
            int x = st.top();
            st.pop();
            return x;
        }
        
    }
    
    void increment(int k, int val) {

        if(st.empty()) return;

        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }

        int count = 0;
        while(!temp.empty()){
            int x = temp.top();
            temp.pop();

            count++;
            if(count <= k){
                x += val;
            }
            st.push(x);
        }

    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
